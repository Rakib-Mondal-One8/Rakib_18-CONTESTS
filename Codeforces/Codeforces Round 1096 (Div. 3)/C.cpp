#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#ifdef Rakib_18
#include "debug.hpp"
#else
#define debug(...)
#endif
/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
void RakibOne8()
{
	int n;
	cin >> n;

	vector<int>a(n);
	for (auto &x : a)cin >> x;

	vector<int>div6, div2, div3, left;
	for (auto x : a) {
		if (x % 6 == 0)div6.push_back(x);
		else if (x % 3 == 0)div3.push_back(x);
		else if (x % 2 == 0)div2.push_back(x);
		else left.push_back(x);
	}
	debug(div2, div3, div6, left);

	for (auto x : div6)cout << x << " ";
	for (auto x : div2)cout << x << " ";
	for (auto x : left)cout << x << " ";
	for (auto x : div3)cout << x << " ";
	cout << nl;
}
int32_t main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t = 1;
	cin >> t;
	while (t--)
	{
		RakibOne8();
	}
	return 0;
}