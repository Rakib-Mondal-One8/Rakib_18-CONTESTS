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
const int mod = 998244353;
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

	string s;
	cin >> s;

	vector<vector<vector<int>>>dp(n + 1, vector<vector<int>>(2, vector<int>(2)));
	//Base
	for (int j = 0; j < 2; j++) {
		for (int k = 0; k < 2; k++) {
			dp[n][j][k] = 1;
		}
	}


	for (int i = n - 1; i >= 2; i--) {
		for (int j = 0; j < 2; j++) { // (i-2)th color
			for (int k = 0; k < 2; k++) { // (i-1)th color

				if (j == 0) {
					if (s[i] == '?' || s[i] == '1') {
						dp[i][j][k] = dp[i + 1][k][1];
					}
				}
				if (j == 1) {
					if (s[i] == '?' || s[i] == '0') {
						dp[i][j][k] = dp[i + 1][k][0];
					}
				}

			}
		}
	}
	debug(s);

	int answer = 0;
	//00
	if ((s[0] == '?' || s[0] == '0') && (s[1] == '0' || s[1] == '?')) {
		debug(dp[2][0][0]);
		answer += dp[2][0][0];
	}
	//01
	if ((s[0] == '?' || s[0] == '0') && (s[1] == '1' || s[1] == '?')) {
		debug(dp[2][0][1]);
		answer += dp[2][0][1];
	}
	//10
	if ((s[0] == '?' || s[0] == '1') && (s[1] == '0' || s[1] == '?')) {
		debug(dp[2][1][0]);
		answer += dp[2][1][0];
	}
	//11
	if ((s[0] == '?' || s[0] == '1') && (s[1] == '1' || s[1] == '?')) {
		debug(dp[2][1][1]);
		answer += dp[2][1][1];
	}

	cout << answer << nl;

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