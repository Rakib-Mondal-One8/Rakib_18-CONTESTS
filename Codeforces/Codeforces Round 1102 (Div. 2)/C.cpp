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

	vector<int>a(n);

	for (int i = 0; i < n; i++)cin >> a[i];


	for (int i = 0; i < n; i++) {
		vector<int>prefixMax(n - 1);
		vector<int>suffixMax(n - 1);

		prefixMax[0] = a[i];
		int index = (i + 1) % n;
		for (int j = 1; j < n - 1; j++) {
			if (index == i)break;
			index %= n;
			prefixMax[j] = max(prefixMax[j - 1], (a[index]));
			index++;
		}
		debug(prefixMax);

		suffixMax[n - 2] = a[(n + (i - 1)) % n];
		index = (n + (i - 2)) % n;
		for (int j = n - 3; j >= 0; j--) {
			if (index == i)break;
			index = (n + (index)) % n;
			suffixMax[j] = max(suffixMax[j + 1], (a[index]));
			index--;
		}
		debug(suffixMax);

		int mxP = 0;
		int p = (i + 1) % n;

		vector<int>answer(n);
		answer[i] = 0;
		for (int j = 1; j <= n - 1; j++) {
			p %= n;
			answer[p] = min(prefixMax[mxP], suffixMax[mxP]);
			mxP++;
			p++;
		}

		cout << accumulate(answer.begin(), answer.end(), 0LL) << " ";

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