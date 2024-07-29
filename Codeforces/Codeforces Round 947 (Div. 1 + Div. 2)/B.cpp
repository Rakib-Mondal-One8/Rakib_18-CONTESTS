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
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, bool> track;
    loop(i, 0, n - 1)
    {
        cin >> a[i];
        track[a[i]] = true;
    }
    if (track.find(1) != track.end())
    {
        Yes;
        return;
    }
    sort(a.begin(), a.end());
    map<int, bool> track2;
    loop(i, 0, n - 1)
    {
        int val = a[i];
        for (int i = 2; i * i <= n; i++)
        {
            if (val % i == 0)
            {
                while (val % i == 0)
                {
                    val /= i;
                    track2[i] = true;
                }
            }
            if (track2.size() == 2)
                break;
        }
        if (val > 1)
            track2[val] = true;
        if (track2.size() == 2)
            break;
    }
    bool ok = true;
    loop(i, 0, n - 1)
    {
        int cnt = 0;
        for (auto v : track2)
        {
            if (a[i] % v.first)
                cnt++;
            if (cnt == 2)
            {
                ok = false;
                break;
            }
        }
        if (!ok)
            break;
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