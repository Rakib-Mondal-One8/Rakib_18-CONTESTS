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

	string s;
	cin >> s;

	if (n % 2)cout << "NO" << nl;
	else {
		int openCnt = 0, closeCnt = 0;
		for (auto c : s) {
			if (c == '(')openCnt++;
			else closeCnt++;
		}
		if (openCnt == closeCnt)cout << "YES" << nl;
		else cout << "NO" << nl;
	}
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