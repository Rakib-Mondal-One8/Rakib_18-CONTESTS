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
        int n, h;
        cin >> n >> h;
        vector<int> e(n);
        int x = 0;
        loop(i, 0, n - 1)
        {
            cin >> e[i];
        }
        sort(e.rbegin(), e.rend());
        loop(i, 0, n - 1)
        {
            h -= e[i];
            if (h <= 0)
            {
                x = e[i];
                break;
            }
        }
        cout << x << nl;
    }
    return 0;
}