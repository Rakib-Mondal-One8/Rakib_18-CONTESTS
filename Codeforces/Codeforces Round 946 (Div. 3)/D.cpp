#include <bits/stdc++.h>
typedef long long ll;
#define pi pair<int, int>
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
    cin >> n;
    string s;
    cin >> s;
    vector<pi> step;
    pi sum;
    for (char c : s)
    {
        if (c == 'N')
        {
            step.push_back({0, 1});
            sum.first += 0;
            sum.second += 1;
        }
        else if (c == 'S')
        {
            step.push_back({0, -1});
            sum.first += 0;
            sum.second -= 1;
        }
        else if (c == 'E')
        {
            step.push_back({1, 0});
            sum.first += 1;
            sum.second += 0;
        }
        else
        {
            step.push_back({-1, 0});
            sum.first -= 1;
            sum.second += 0;
        }
    }
    if ((sum.first % 2 == 0) && (sum.second % 2 == 0))
    {
        int fsthalf = (sum.first / 2);
        int sechalf = (sum.second / 2);
        pi need = {fsthalf, sechalf};
        
    }
    else
    {
        No;
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