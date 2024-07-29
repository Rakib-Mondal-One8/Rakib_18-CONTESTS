#include <bits/stdc++.h>
typedef long long ll;
#define Yes cout << "YES" << '\n'
#define No cout << "NO" << '\n'
#define nl '\n';
#define for(i, s, n) for (int i = s; i <= n; i++)
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        int n, a, b;
        cin >> n >> a >> b;

        if (n % 2 == 1)
        {
            if ((n * a) > (((n / 2) * b) + (n % 2 * a)))
            {
                cout << ((n / 2) * b + (n % 2 * a)) << nl
            }
            else
            {
                cout << n * a << nl
            }
        }
        else
        {
            if ((n * a) > ((n / 2) * b))
            {
                cout << ((n / 2) * b) << nl
            }
            else
            {
                cout << n * a << nl
            }
        }
    }
    return 0;
}