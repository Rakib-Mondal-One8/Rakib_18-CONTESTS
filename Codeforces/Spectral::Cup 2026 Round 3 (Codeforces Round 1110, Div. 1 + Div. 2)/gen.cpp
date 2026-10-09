#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int rand(int low,int high){ 
	return low + rand() % (high - low + 1);
}
int32_t main(int argc, char* argv[]) {
	srand(atoi(argv[1])); // seed passed from stress script
	int n = rand(1,100); // small n for easy debugging
	int k = rand(1,1000);
	cout << n <<" "<<k<< "\n";
	for (int i = 0; i < n; i++) cout << rand(1,1e8) << " \n"[i == n-1];
}