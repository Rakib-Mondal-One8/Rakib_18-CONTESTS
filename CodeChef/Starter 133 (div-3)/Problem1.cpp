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
        int n;
        cin >> n;

        int cow = (n / 4);
        int chick = min((n / 2), (n % 4) / 2);
        if (n % 4 == 0)
        {
            cout << cow << nl
        }
        else
        {
            cout << cow + chick << nl;
        }
    }
    return 0;
}