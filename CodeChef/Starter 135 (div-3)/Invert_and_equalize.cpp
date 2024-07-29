/*
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
/*
void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> zero;
    vector<int> one;
    int l = 0, r = 0;
    while (r < n)
    {
        int ilen = 0;
        while (r < n && s[r] == '0')
        {
            ilen = (r - l + 1);
            r++;
        }
        if (ilen != 0)
            zero.push_back(ilen);
        while (r < n && s[r] == '1')
        {
            r++;
        }
        l = r;
    }
    l = 0, r = 0;
    while (r < n)
    {
        int ilen = 0;
        while (r < n && s[r] == '1')
        {
            ilen = (r - l + 1);
            r++;
        }
        if (ilen != 0)
            one.push_back(ilen);
        while (r < n && s[r] == '0')
        {
            r++;
        }
        l = r;
    }
    cout << min(zero.size(), one.size()) << nl;
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
*/

// Approach - 2

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
    string s;
    cin >> s;
    int c1 = 0;
    int c0 = 0;
    if (s[0] == '0')
        c0++;
    loop(i, 0, n - 1)
    {
        if (s[i] == '0' && s[i - 1] == '1')
            c0++;
    }
    if (s[0] == '1')
        c1++;
    loop(i, 0, n - 1)
    {
        if (s[i] == '1' && s[i - 1] == '0')
            c1++;
    }
    int ans = 0;
    ans = min(c0, c1);
    cout<<ans<<nl;
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