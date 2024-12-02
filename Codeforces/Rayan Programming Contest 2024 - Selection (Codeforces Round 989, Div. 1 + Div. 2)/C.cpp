#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
/*Problem Link -> */
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
using namespace chrono;
template <typename T>
using pbds = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using pbdms = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
/*Debug*/
#ifdef Rakib_18
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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void init_code() {
#ifdef Rakib_18
	freopen("Error.txt", "w", stderr);
#endif
}
const ll mod = 1e9 + 7;
ll inv(ll i) {if (i == 1) return 1; return (mod - ((mod / i) * inv(mod % i)) % mod) % mod;}
bool isPrime(ll n) {if (n <= 1)return false; if (n <= 3)return true; if (n % 2 == 0 || n % 3 == 0)return false; for (ll i = 5; i * i <= n; i += 6) {if (n % i == 0 || n % (i + 2) == 0)return false;} return true;}
ll lcm(ll a, ll b) {return (a / __gcd(a, b)) * b;}
int nXOR(int n) {if (n % 4 == 0)return n; if (n % 4 == 1)return 1; if (n % 4 == 2)return n + 1; return 0;}
/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
void solve()
{
	int n, m;
	cin >> n >> m;

	vector<string>grid(n);
	loop(i, 0, n - 1)cin >> grid[i];

	if (n == 1 && m == 1) {
		cout << 0 << nl;
		return;
	}
	vector<vector<int>>vis(n, vector<int>(m, 0));
	queue<pi>q;
	loop(i, 0, n - 1) {
		loop(j, 0, m - 1) {
			if (i == 0 && grid[i][j] == 'U')q.push({i, j}), vis[i][j] = 1;
			if (i == n - 1 && grid[i][j] == 'D')q.push({i, j}), vis[i][j] = 1;
			if (j == 0 && grid[i][j] == 'L')q.push({i, j}), vis[i][j] = 1;
			if (j == m - 1 && grid[i][j] == 'R')q.push({i, j}), vis[i][j] = 1;
		}
	}

	while (!q.empty()) {
		auto [i, j] = q.front();
		q.pop();

		if (i - 1 >= 0 && !vis[i - 1][j] && grid[i - 1][j] == 'D')
			q.push({i - 1, j}), vis[i - 1][j] = 1;
		if (i + 1 < n && !vis[i + 1][j] && grid[i + 1][j] == 'U')
			q.push({i + 1, j}), vis[i + 1][j] = 1;
		if (j - 1 >= 0 && !vis[i][j - 1] && grid[i][j - 1] == 'R')
			q.push({i, j - 1}), vis[i][j - 1] = 1;
		if (j + 1 < m && !vis[i][j + 1] && grid[i][j + 1] == 'L')
			q.push({i, j + 1}), vis[i][j + 1] = 1;

		auto check = [&](int ii, int jj) {
			if (ii < 0 || ii >= n || jj < 0 || jj >= m)return;

			if (vis[ii][jj] || grid[ii][jj] != '?')return;

			if (ii - 1 >= 0 && !vis[ii - 1][jj])return;

			if (ii + 1 < n && !vis[ii + 1][jj])return;

			if (jj - 1 >= 0 && !vis[ii][jj - 1])return;

			if (jj + 1 < m && !vis[ii][jj + 1])return;

			vis[ii][jj] = 1;
			return;
		};

		check(i - 1, j);
		check(i + 1, j);
		check(i, j - 1);
		check(i, j + 1);
	}
	int ans = 0;
	loop(i, 0, n - 1)loop(j, 0, m - 1)if (!vis[i][j])ans++;
	cout << ans << nl;
}
int main()
{
	init_code();
	fastio();
	int t = 1;
	cin >> t;
	auto start1 = high_resolution_clock::now();
	while (t--)
	{
		solve();
	}
	auto stop1 = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop1 - start1);
#ifdef Rakib_18
	cerr << "Time: " << duration . count() / 1000 << " ms" << endl;
#endif
	return 0;
}