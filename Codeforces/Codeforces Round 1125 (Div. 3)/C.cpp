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

void RakibOne8() {
    int n;
    cin >> n;

    vector<int>v(n);
    for (auto &x : v)cin >> x;
    debug(v);


    auto go = [&](int x, vector<int>&ending)->int{
        if (sz(ending) == 0)return 0;
        int low = 0, high = sz(ending);
        int res = -1;
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (ending[mid] < x) {
                res = mid;
                low = mid + 1;
            } else high = mid - 1;
        }
        debug(x, sz(ending), ending, res);
        return res + 1;

    };
    map<int, int>mp1;
    map<int, vector<int>>endingIndex1;
    int notIntersect = 0;
    for (int i = 0; i + 4 < n; i += 2) {
        int cur = v[i] + v[i + 2] - v[i + 4];
        mp1[cur]++;

        notIntersect += go(i, endingIndex1[cur]);
        endingIndex1[cur].push_back(i + 4);
    }


    map<int, int>mp2;
    map<int, vector<int>>endingIndex2;
    for (int i = 1; i + 4 < n; i += 2) {
        int cur = v[i] + v[i + 2] - v[i + 4];

        notIntersect += go(i, endingIndex2[cur]);
        endingIndex2[cur].push_back(i + 4);
        mp2[cur]++;
    }
    debug(mp1, mp2);
    debug(notIntersect);



    int answer = 0;
    for (auto [x, y] : mp1) {
        answer += mp2[x] * y;
    }

    cout << answer + notIntersect << nl;

}
int32_t main() {
    init_code();
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1;
    cin >> t;
    auto start1 = high_resolution_clock::now();
    while (t--) {
        RakibOne8();
    }
    auto stop1 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop1 - start1);
#ifdef Rakib_18
    cerr << "Time: " << duration . count() / 1000 << " ms" << endl;
#endif
    return 0;
}