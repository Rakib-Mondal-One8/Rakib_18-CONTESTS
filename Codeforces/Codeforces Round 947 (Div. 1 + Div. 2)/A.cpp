#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
typedef long long ll;
#define pi pair<int, int>;
#define pll pair<ll, ll>;
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
bool is_sorted(vector<int> &a, int n)
{
    vector<int> b(a);
    sort(b.begin(), b.end());
    for (int i = 0; i < n; i++)
    {
        if (b[i] != a[i])
            return false;
    }
    return true;
}
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    loop(i, 0, n - 1)
    {
        cin >> a[i];
    }
    if (is_sorted(a, n))
    {
        Yes;
        return;
    }
    vector<int> b;
    vector<int> tmp;
    int idx = -1;
    loop(i, 0, n - 1)
    {
        tmp.push_back(a[i]);
        if (is_sorted(tmp, tmp.size()))
        {
            b = tmp;
        }
        else
        {
            idx = i;
            break;
        }
    }
    bool ok = true;
    int mx = INT_MIN;
    int prev = a[idx];
    loop(i, idx + 1, n - 1)
    {
        if (a[i] < prev)
        {
            ok = false;
            break;
        }
        prev = a[i];
    }
    loop(i, idx, n - 1)
    {
        mx = max(a[i], mx);
    }
    loop(i, 0, idx-1)
    {
        if (b[i] < mx)
        {
            ok = false;
            break;
        }
    }
    (ok) ? Yes : No;
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