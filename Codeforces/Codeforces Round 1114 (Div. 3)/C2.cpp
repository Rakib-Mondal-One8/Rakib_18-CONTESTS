#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define sz(x) ((int)(x).size())
#define nl '\n'
#ifdef Rakib_18
#include "debug.hpp"
#else
#define debug(...)
#endif
void init_code() {
#ifdef Rakib_18
	//freopen("in.txt", "r", stdin);
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


int go(vector<int>&one1,vector<int>&one2){

	vector<int>odd1,even1;
	for(int i=0;i<sz(one1);i++){
		if(one1[i]%2)odd1.push_back(one1[i]);
		else even1.push_back(one1[i]);
	}


	vector<int>odd2,even2;
	for(int i=0;i<sz(one2);i++){
		if(one2[i]%2)odd2.push_back(one2[i]);
		else even2.push_back(one2[i]);
	}

	debug(even1,even2);
	debug(odd1,odd2);
	if(odd1.size()==odd2.size() && sz(even1) == sz(even2)){
		int answer = 0;
		for(int i=0;i<sz(even1);i++){
			int dist =abs(even1[i]-even2[i]); 
			answer+= (dist>0)?dist-1:dist;
		}
		for(int i=0;i<sz(odd1);i++){
			int dist =abs(odd1[i]-odd2[i]); 
			answer+= (dist>0)?dist-1:dist;
		}

		return answer;
	}
	else return -1;
}
void RakibOne8()
{
	int n;
	cin>>n;

	string s1,s2;
	cin>>s1>>s2;

	vector<int>one1,one2,zero1,zero2;
	for(int i=1;i<=n;i++){
		if(s1[i-1] == '1')one1.push_back(i);
		else zero1.push_back(i);

		if(s2[i-1]=='1')one2.push_back(i);
		else zero2.push_back(i);
	}

	if(sz(one1)!=sz(one2)){
		cout<<-1<<nl;
		return;
	}

	int answer = min(go(one1,one2),go(zero1,zero2));
	cout<<answer<<nl;

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