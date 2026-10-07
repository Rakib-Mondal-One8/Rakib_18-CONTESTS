#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int rand(int low, int high) {
    return low + rand() % (high - low + 1);
}
int32_t main(int argc, char* argv[]) {
    srand(atoi(argv[1])); // seed passed from stress script
    int n = rand(0, 10); // small n for easy debugging
    int x = rand(0, 10);
    int y = rand(0, 10);
    cout << n << " " << x << " " << y << "\n";
    // for (int i = 0; i < n; i++) cout << rand(1, 100) << " \n"[i == n - 1];
}