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
    int n;
    string s;
    cin >> n >> s;
    int ans = 0, total_a = 0, b = 0;
    int cur_a = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'a')
            cur_a++;
        else if (s[i] == 'b')
        {
            total_a += cur_a;
            b = 1;
            cur_a = 0;
        }
        else
        {
            if (b == 1)
            {
                if (total_a == 0)
                {
                    b = 0;
                }
                else
                {
                    ans++;
                    total_a--;
                }
            }
        }
    }
    cout << ans << nl;
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