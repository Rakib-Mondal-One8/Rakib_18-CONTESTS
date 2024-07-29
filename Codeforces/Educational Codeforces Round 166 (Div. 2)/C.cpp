#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

typedef long long ll;
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
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
/*Debug*/
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.first); cerr << ","; _print(p.second); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

void init_code() {
#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

}
bool isPrime(ll n) {
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    for (ll i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}
ll lcm(ll a, ll b) {
    return (a / __gcd(a, b)) * b;
}
int nXOR(int n) {
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
const int N = 5e5 + 5;
int n, m;
ll a[N][2];
ll mx[N];
ll sum[N][2];
ll canGet[N][2];
void build() {
    for (int i = 1; i <= n + m + 1; i++) {
        mx[i] = mx[i - 1] + max(a[i][0], a[i][1]);
        sum[i][0] = sum[i - 1][0] + a[i][0];
        sum[i][1] = sum[i - 1][1] + a[i][1];
        canGet[i][0] = canGet[i - 1][0] + ((a[i][0] > a[i][1]) ? 1 : 0);
        canGet[i][1] = canGet[i - 1][1] + ((a[i][1] > a[i][0]) ? 1 : 0);
    }
}
ll getSumStrong(int l, int r)
{
    if (l > r)
        return 0;
    return mx[r] - mx[l - 1];
}

int bs_n(int bad)
{
    int l = 0, h = n + m + 1;
    int ans = n + m + 1;
    while (l <= h)
    {
        int mid = (l + h) / 2;
        int get = canGet[mid][0];
        if (mid >= bad)
        {
            get -= (a[bad][0] > a[bad][1]);
        }
        if (get > n)
        {
            h = mid - 1;
        }
        else if (get == n)
        {
            h = mid - 1;
            ans = mid;
        }
        else {
            // koto < n
            l = mid + 1;
        }
    }
    return ans;
}

int bs_m(int bad)
{
    int l = 0, h = n + m + 1;
    int ans = n + m + 1;
    while (l <= h)
    {
        int mid = (l + h) / 2;
        int get = canGet[mid][1];
        if (mid >= bad)
        {
            get -= (a[bad][1] > a[bad][0]);
        }
        if (get > m)
        {
            h = mid - 1;
        }
        else if (get == m)
        {
            h = mid - 1;
            ans = mid;
        }
        else {
            l = mid + 1;
        }
    }
    return ans;
}
void solve()
{
    cin >> n >> m;
    loop(i, 1, n + m + 1) {
        cin >> a[i][0];
    }
    loop(i, 1, n + m + 1) {
        cin >> a[i][1];
    }
    build();
    for (int i = 1; i <= n + m + 1; i++) {
        int idx_n = bs_n(i);
        int idx_m = bs_m(i);
        ll ans = 0;
        if (idx_n <= idx_m)
        {
            ans += getSumStrong(1, idx_n);
            ans += sum[n + m + 1][1] - sum[idx_n][1];
            if (i <= idx_n)
            {
                ans -= max(a[i][0], a[i][1]);
            }
            else {
                ans -= a[i][1];
            }
        }
        else {
            ans += getSumStrong(1, idx_m);
            ans += sum[n + m + 1][0] - sum[idx_m][0];
            if (i <= idx_m)
            {
                ans -= max(a[i][0], a[i][1]);
            }
            else {
                ans -= a[i][0];
            }
        }
        cout << ans << " ";
    }
    cout << "\n";

}
int main()
{
    init_code();
    fastio();
    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }
    return 0;
}

