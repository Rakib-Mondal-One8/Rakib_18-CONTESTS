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
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    map<vector<int>, int> m;
    ll ans = 0;

    for (int i = 0; i < n - 2; i++)
    {
        vector<int> p = {a[i], a[i + 1], 0};
        vector<int> q = {a[i], 0, a[i + 2]};
        vector<int> r = {0, a[i + 1], a[i + 2]};
        vector<int> s = {a[i], a[i + 1], a[i + 2]};

        int pairs = m[p] + m[q] + m[r] - 3 * m[s];
        m[p]++;
        m[q]++;
        m[r]++;
        m[s]++;

        ans += pairs;
    }
    cout << ans << endl;
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