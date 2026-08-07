#include <bits/stdc++.h>
using namespace std;
#define int long long
#define sz(x) ((int)(x).size())
#define nl '\n'
#ifdef Rakib_18
#include "debug.hpp"
#else
#define debug(...)
#endif
void init_code() {
#ifdef Rakib_18
	freopen("Error.txt", "w", stderr);
#endif
}
using namespace chrono;

/*_________________________________________________________________________________________________________________________________________________________________________________________________________________________*/
const int mod = 1e9 + 7;
int expo(int a, int b, int mod) { int res = 1; while (b > 0) { if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1; } return res; }
int mminvprime(int a, int b) { return expo(a, b - 2, b); }
int inv(int i) { if (i == 1) return 1; return (mod - ((mod / i) * inv(mod % i)) % mod) % mod; }
bool isPrime(int n) { if (n <= 1)return false; if (n <= 3)return true; if (n % 2 == 0 || n % 3 == 0)return false; for (int i = 5; i * i <= n; i += 6) { if (n % i == 0 || n % (i + 2) == 0)return false; } return true; }
int lcm(int a, int b) { return (a / __gcd(a, b)) * b; }
int mod_add(int a, int b, int m) { a = a % m; b = b % m; return (((a + b) % m) + m) % m; }
int mod_mul(int a, int b, int m) { a = a % m; b = b % m; return (((a * b) % m) + m) % m; }
int mod_sub(int a, int b, int m) { a = a % m; b = b % m; return (((a - b) % m) + m) % m; }
int mod_div(int a, int b, int m) { a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m; }  //only for prime m
int nXOR(int n) { if (n % 4 == 0)return n; if (n % 4 == 1)return 1; if (n % 4 == 2)return n + 1; return 0; }
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
/*_________________________________________________________________________________________________________________________________________________________________________________________________________________________*/

void RakibOne8()
{
	int n, m, x, y;
	cin >> n >> m >> x >> y;

	vector<int>a(x);
	for (auto &v : a)cin >> v;
	sort(a.rbegin(), a.rend());
	vector<int>b(y);
	for (auto &v : b)cin >> v;
	sort(b.rbegin(), b.rend());

	int answer1 = 0;
	set<int>s1;
	for (int i = 0; i < min(y, m - 1); i++) {
		s1.insert(b[i]);
	}

	int j = 0;
	for (int i = 0; j < x && i < min(x, n); i++) {
		if (!s1.count(a[j])) {

			s1.insert(a[j]);
		}
		else {
			j++;
			i--;
		}
	}
	debug(s1);




	int answer2 = 0;
	set<int>s2;
	for (int i = 0; i < min(y, m); i++) {
		s2.insert(b[i]);
	}

	j = 0;
	for (int i = 0; j < x && i < min(x, n - 1); i++) {
		if (j < n && !s2.count(a[j])) {
			s2.insert(a[j]);
		}
		else {
			j++;
			i--;
		}
	}


	int answer3 = 0;
	set<int>s3;
	for (int i = 0; i < min(x, n - 1); i++) {
		s3.insert(a[i]);
	}

	j = 0;
	for (int i = 0; j < y && i < min(y, m); i++) {
		if (!s3.count(b[j])) {

			s3.insert(b[j]);
		}
		else {
			j++;
			i--;
		}
	}


	int answer4 = 0;
	set<int>s4;
	for (int i = 0; i < min(x, n); i++) {
		s4.insert(a[i]);
	}

	j = 0;
	for (int i = 0; j < y && i < min(y, m - 1); i++) {
		if (j < n && !s4.count(b[j])) {
			s4.insert(b[j]);
		}
		else {
			j++;
			i--;
		}
	}


	for (auto x : s1)answer1 += x;
	for (auto x : s2)answer2 += x;
	for (auto x : s3)answer3 += x;
	for (auto x : s4)answer4 += x;

	cout << max({answer1, answer2, answer3, answer4}) << nl;
}
int32_t main()
{
	init_code();
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t = 1;
	cin >> t;
	auto start1 = high_resolution_clock::now();
	while (t--)
	{
		RakibOne8();
	}
	auto stop1 = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop1 - start1);
#ifdef Rakib_18
	cerr << "Time: " << duration . count() / 1000 << " ms" << endl;
#endif
	return 0;
}