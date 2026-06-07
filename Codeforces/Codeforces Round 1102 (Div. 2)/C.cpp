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
	int n;
	cin >> n;

	vector<int>a(n + 1);

	for (int i = 0; i < n; i++)cin >> a[i];

	for (int i = 0; i < n; i++) {

		vector<int>res(n, -1);
		res[i] = 0;

		int right = n;
		if (i + 1 == n) {
			res[0] = a[i];
		}
		else {
			res[i + 1] = a[i];
			right = i + 1;
		}

		int left = -1;
		if (i - 1 < 0) {
			res[n - 1] = a[n - 1];
		}
		else {
			res[i - 1] = a[i - 1];
			left = i - 1;
		}

		if (right < n) {
			int mx = res[right];
			for (int j = right; j < n - 1; j++) {
				mx = max(mx, a[j]);
				if (res[j + 1] == -1)
					res[j + 1] = mx;
			}
		}


		if (left > -1) {
			int mx = res[left];
			for (int j = left - 1; j >= 0; j--) {
				mx = max(mx, a[j]);
				res[j] = mx;
			}
		}

		debug(res);
		int ans = accumulate(res.begin(), res.end(), 0LL);

		cout << ans << " ";


	}
	cout << nl;
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