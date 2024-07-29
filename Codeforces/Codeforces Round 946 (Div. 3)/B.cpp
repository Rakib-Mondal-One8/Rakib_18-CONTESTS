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
    cin >> n;
    string s;
    cin >> s;
    set<char> seq;
    map<char, char> mp;
    for (char c : s)
    {
        seq.insert(c);
    }
    int limit = seq.size() / 2;
    limit += seq.size() % 2;
    while (limit--)
    {
        char b = *seq.begin();
        char e = *seq.rbegin();
        mp[b] = e;
        mp[e] = b;
        seq.erase(seq.find(b));
        if (b != e)
            seq.erase(seq.find(e));
    }
    string ans = "";
    for (char c : s)
    {
        ans += mp[c];
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