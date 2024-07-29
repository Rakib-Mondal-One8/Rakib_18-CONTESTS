#include <bits/stdc++.h>
typedef long long ll;
#define Yes cout << "YES" << '\n'
#define No cout << "NO" << '\n'
#define nl '\n';
#define loop(i, s, n) for (int i = s; i <= n; i++)
using namespace std;
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        int x;
        cin >> x;

        int mx = INT_MIN;
        int y = 0;
        for (int i = 1; i < x; i++)
        {
            if (i < x)
            {
                if (mx < (gcd(x, i) + i))
                {
                    mx = (gcd(x, i) + i);
                    y = i;
                }
            }
        }
        cout << y << nl;
    }
    return 0;
}