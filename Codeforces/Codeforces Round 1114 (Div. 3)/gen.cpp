#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int rand(int low,int high){ 
	return low + rand() % (high - low + 1);
}
int32_t main(int argc, char* argv[]) {
	srand(atoi(argv[1])); // seed passed from stress script
	int n = rand(1,10); // small n for easy debugging
	// int x = rand(2,10);
	cout <<n<< "\n";
	for (int i = 0; i < n; i++) cout << char(rand(97,122));
		cout<<"\n";
}