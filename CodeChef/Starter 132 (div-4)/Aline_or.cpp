#include <bits/stdc++.h>
typedef long long ll;
#define Yes cout << "YES" << '\n'
#define No cout << "NO" << '\n'
#define nl '\n';
#define loop(i, s, n) for (ll i = s; i <= n; i++)
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

        vector<bool> a(k);
        loop(i, 1, n)
        {
            string s;
            cin >> s;
            reverse(s.begin(), s.end());
            int cnt = 0;
            int idx = -1;
            for (int j = 0; j < k; j++)
            {
                if (s[j] == '1')
                {
                    idx = j;
                    cnt++;
                }
            }
            if (cnt == 1)
                a[idx] = true;
        }
        bool ok = true;
        loop(i, 0, k - 1)
        {
            if (!a[i])
            {
                ok = false;
                break;
            }
        }
        if (ok)
            Yes;
        else
            No;
    }
    return 0;
}
