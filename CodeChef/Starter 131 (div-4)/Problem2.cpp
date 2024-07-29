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
        int n, x, y;
        cin >> n >> x >> y;

        vector<int> a(n);
        loop(i, 0, n - 1)
        {
            cin >> a[i];
        }
        ll totalcost = 0;
        loop(i, 0, n - 1)
        {
            if (a[i] * x > y)
            {
                totalcost += y;
            }
            else
            {
                totalcost += (a[i] * x);
            }
        }
        cout << totalcost << nl;
    }
    return 0;
}