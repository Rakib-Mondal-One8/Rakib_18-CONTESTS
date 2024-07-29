#include <bits/stdc++.h>
typedef long long ll;
#define pi pair<int, int>;
#define pll pair<ll, ll>;
#define Yes cout << "YES" << '\n'
#define No cout << "NO" << '\n'
#define nl '\n'
#define loop(i, s, n) for (ll i = s; i <= n; i++)
using namespace std;
bool isPrime(ll n)
{
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    for (ll i = 5; i * i <= n; i += 6)
    {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}
ll lcm(ll a, ll b)
{
    return (a / __gcd(a, b)) * b;
}
/*--------------------------------------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------------------------------------*/
void solve()
{
    int x, y;
    cin >> x >> y;
    if (x == 0 && y == 0)
    {
        cout << 0 << nl;
    }
    else
    {
        ll req = y / 2;
        req += y % 2;
        ll occy = (y * 4);
        ll occx = (x * 1);
        ll remspace = (req * 15) - occy;
        if (remspace >= occx)
        {
            cout << req << nl;
        }
        else
        {
            ll remx = occx - remspace;
            ll extra = 1;
            loop(i, 1, 300)
            {
                if (15 * i >= remx)
                {
                    req += i;
                    break;
                }
            }
            cout << req << nl;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }
    return 0;
}