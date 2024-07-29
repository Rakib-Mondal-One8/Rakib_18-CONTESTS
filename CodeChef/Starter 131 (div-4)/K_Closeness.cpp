#include <bits/stdc++.h>
typedef long long ll;
#define Yes cout << "YES" << '\n'
#define No cout << "NO" << '\n'
#define nl '\n';
#define loop(i, s, n) for (int i = s; i <= n; i++)
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> v(n);
        int mx = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            mx = max(mx, v[i]);
        }

        for (int i = 0; i < n; i++)
        {
            v[i] += ((mx - v[i]) / k) * k;
        }
        sort(v.begin(), v.end());
        int ans = v[n - 1] - v[0];
        for (int i = 0; i < n - 1; i++)
        {
            // cout << v[i] + k - v[i + 1] << " ";
            if (v[i] + k - v[i + 1] < ans)
            {
                ans = v[i] + k - v[i + 1];
            }
        }

        cout << ans << endl;
    }
    return 0;
}