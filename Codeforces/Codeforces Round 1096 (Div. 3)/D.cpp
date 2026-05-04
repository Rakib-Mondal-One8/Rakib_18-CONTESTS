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
	int m = 2 * n;
	vector<int>a(m);
	for (auto &x : a)cin >> x;

	vector<int>zeroIdx;
	for (int i = 0; i < m; i++)if (a[i] == 0)zeroIdx.push_back(i);

	int ans = 0;
	auto go = [&](int low, int high) {
		for (int i = low, j = high; i < j; i++, j--) {
			if (a[i] != a[j])return;
		}

		int left = low, right = high;
		while ((left > 0) && (right + 1 < m) && (a[left - 1] == a[right + 1])) {
			left--;
			right++;
		}
		set<int>s;
		for (int i = left; i <= right; i++)s.insert(a[i]);

		int mex = 0;
		while (s.count(mex))mex++;
		ans = max(ans, mex);
	};

	go(zeroIdx[0], zeroIdx[0]);
	go(zeroIdx[1], zeroIdx[1]);
	go(zeroIdx[0], zeroIdx[1]);

	cout << ans << nl;
}
int32_t main()
{
	init_code();
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t = 1;
	cin >> t;
	while (t--)
	{
		RakibOne8();
	}
	return 0;
}