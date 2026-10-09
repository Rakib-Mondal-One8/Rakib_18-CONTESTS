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
    // freopen("Error.txt", "w", stderr);
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
const int INF = 1e9+7;
void RakibOne8() {
    int n, c;
    cin >> n >> c;

    list<pair<int, int>>v;
    list<pair<int, int>>::iterator w[n];

    map < pair<int, int>, int > pos;
    vector<pair<int, int>>mxArr;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        w[i] = v.insert(v.end(), {x, i});
        pos[ {x, i}] = i;
        mxArr.push_back({x, i});
    }
    sort(mxArr.begin(), mxArr.end());
    debug(mxArr);

    map<pair<int, int>, int>deleted;

    int answer = 0;
    while (sz(mxArr) > 0) {
        auto [x, y] = mxArr.back();
        mxArr.pop_back();

        if (deleted[ {x, y}])continue;



        auto it = w[pos[ {x, y}]];
        int mnNeighbour = INF;
        auto mnNeighbourIt  = it;
        int index;

        if (next(it) != v.begin() && (*next(it)).first < c) {
            mnNeighbour = min(mnNeighbour, (*next(it)).first);
            index = (*next(it)).second;
            mnNeighbourIt = next(it);
        }
        if (it != v.begin() && ( *prev(it)).first < c) {
            mnNeighbour = min(mnNeighbour, (*prev(it)).first);
            index = (*prev(it)).second;
            mnNeighbourIt = prev(it);
        }

        answer += x - c;

        deleted[ {x, y}] = true;

        if (mnNeighbour != INF && mnNeighbourIt != it && sz(mxArr) > 1) {
            deleted[ {mnNeighbour, index}] = true;
            debug(*mnNeighbourIt)
            v.erase(mnNeighbourIt);
        }

    }

    cout << answer << nl;


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