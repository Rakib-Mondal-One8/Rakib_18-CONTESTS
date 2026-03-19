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
#define sz(x) ((int)(x).size())
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
const int mod = 1e9 + 7;
// const int mod = 998244353;
// const long long mod = 1375927501846395853LL;
bool isPrime(ll n) { if (n <= 1)return false; if (n <= 3)return true; if (n % 2 == 0 || n % 3 == 0)return false; for (ll i = 5; i * i <= n; i += 6) { if (n % i == 0 || n % (i + 2) == 0)return false; } return true; }

/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
struct Mint {
	int val;

	Mint(long long v = 0) {
		if (v < 0) v = v %  + mod;
		if (v >= mod) v %= mod;
		val = v;
	}

	static int mod_inv(int a, int m = mod) {
		int g = m, r = a, x = 0, y = 1;
		while (r != 0) {
			int q = g / r;
			g %= r; swap(g, r);
			x -= q * y; swap(x, y);
		}
		return x < 0 ? x + m : x;
	}
	explicit operator int() const { return val; }
	Mint& operator+=(const Mint &other) { val += other.val; if (val >= mod) val -= mod; return *this; }
	Mint& operator-=(const Mint &other) { val -= other.val; if (val < 0) val += mod; return *this; }
	static unsigned fast_mod(uint64_t x, unsigned m = mod) {
#if !defined(_WIN32) || defined(_WIN64)
		return x % m;
#endif
		unsigned x_high = x >> 32, x_low = (unsigned) x;
		unsigned quot, rem;
		asm("divl %4\n"
		    : "=a" (quot), "=d" (rem)
		    : "d" (x_high), "a" (x_low), "r" (m));
		return rem;
	}
	Mint& operator*=(const Mint &other) { val = fast_mod((uint64_t) val * other.val); return *this; }
	Mint& operator/=(const Mint &other) { return *this *= other.inv(); }
	friend Mint operator+(const Mint &a, const Mint &b) { return Mint(a) += b; }
	friend Mint operator-(const Mint &a, const Mint &b) { return Mint(a) -= b; }
	friend Mint operator*(const Mint &a, const Mint &b) { return Mint(a) *= b; }
	friend Mint operator/(const Mint &a, const Mint &b) { return Mint(a) /= b; }
	Mint& operator++() { val = val == mod - 1 ? 0 : val + 1; return *this; }
	Mint& operator--() { val = val == 0 ? mod - 1 : val - 1; return *this; }
	// friend Mint operator<=(const Mint &a, const Mint &b) { return (int)a <= (int)b; }
	Mint operator++(int32_t) { Mint before = *this; ++*this; return before; }
	Mint operator--(int32_t) { Mint before = *this; --*this; return before; }
	Mint operator-() const { return val == 0 ? 0 : mod - val; }
	bool operator==(const Mint &other) const { return val == other.val; }
	bool operator!=(const Mint &other) const { return val != other.val; }
	Mint inv() const { return mod_inv(val); }
	Mint power(long long p) const {
		assert(p >= 0);
		Mint a = *this, result = 1;
		while (p > 0) {
			if (p & 1) result *= a;
			a *= a, p >>= 1;
		}
		return result;
	}
	friend ostream& operator << (ostream &stream, const Mint &m) { return stream << m.val; }
	friend istream& operator >> (istream &stream, Mint &m) { return stream >> m.val;   }
};

ll lcm(ll a, ll b) { return (a / __gcd(a, b)) * b; }
void solve()
{
	ll a, b, c, m;
	cin >> a >> b >> c >> m;

	ll lcmABC = lcm(a, b);
	lcmABC = lcm(lcmABC, c);

	ll lcmAB = lcm(a, b);
	ll lcmAC = lcm(a, c);
	ll lcmBC = lcm(b, c);

	ll A = m / a, B = m / b, C = m / c;
	ll AB = m / lcmAB, BC = m / lcmBC, AC = m / lcmAC;
	ll ABC = m / lcmABC;

	AB -= ABC;
	AC -= ABC;
	BC -= ABC;

	A -= (AB + AC + ABC);
	B -= (AB + BC + ABC);
	C -= (AC + BC + ABC);



	cout << A * 6 + (AB + AC) * 3 + ABC * 2 << " ";
	cout << B * 6 + (BC + AB) * 3 + ABC * 2 << " ";
	cout << C * 6 + (AC + BC) * 3 + ABC * 2 << nl;
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