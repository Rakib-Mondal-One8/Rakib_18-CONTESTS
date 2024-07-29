#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
typedef long long ll;
#define pi pair<int, int>
#define pll pair<ll, ll>
#define Yes cout << "YES" << '\n'
#define No cout << "NO" << '\n'
#define nl '\n'
#define loop(i, s, n) for (ll i = s; i <= n; i++)
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using pbds = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using pbdms = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

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
int nXOR(int n)
{
    if (n % 4 == 0)
        return n;
    if (n % 4 == 1)
        return 1;
    if (n % 4 == 2)
        return n + 1;
    return 0;
}
/*--------------------------------------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------------------------------------*/
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n + 1);
    loop(i, 0, n - 1)
    {
        cin >> a[i];
    }
    loop(i, 0, n)
    {
        cin >> b[i];
    }
    ll ans = 0;
    ll mini = 1e18;
    loop(i, 0, n - 1)
    {
        ans += abs(a[i] - b[i]);
        ll mn = min(a[i], b[i]);
        ll mx = max(a[i], b[i]);
        if (b.back() >= mn && b.back() <= mx)
        {
            mini = 0;
        }
        mini = min(mini, 1LL * abs(b.back() - a[i]));
        mini = min(mini, 1LL * abs(b.back() - b[i]));
    }
    ans += mini;
    cout << ans + 1 << nl;
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