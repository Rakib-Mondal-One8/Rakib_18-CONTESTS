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

        vector<int> a(n);
        loop(i, 0, n - 1)
        {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        ll mx = 0;
        int turn = 0;
        loop(i, 0, n - 1)
        {
            if (turn < k && (7 - a[i]) > a[i])
            {
                mx += (7 - a[i]);
                turn++;
            }
            else
            {
                mx += a[i];
            }
        }
        cout << mx << nl;
    }
    return 0;
}