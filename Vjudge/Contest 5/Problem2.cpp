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

        int mn = INT_MAX;
        loop(i, 1, n)
        {
            int cookies;
            cin >> cookies;
            if (cookies >= k)
                mn = min(mn, cookies % k);
        }
        if (mn == INT_MAX)
        {

            cout << -1 << nl;
        }
        else
            cout << mn << nl;
    }
    return 0;
}