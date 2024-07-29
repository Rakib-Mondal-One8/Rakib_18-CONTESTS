#include <bits/stdc++.h>
typedef long long ll;
#define Yes cout << "YES" << '\n'
#define No cout << "NO" << '\n'
#define nl '\n';
#define loop(i, s, n) for (ll i = s; i <= n; i++)
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> a(n);
        loop(i, 0, n - 1)
        {
            cin >> a[i];
        }
        ll totalSeg = (1LL * n * (n + 1)) / 2;
        int r = 0;
        vector<int> seg;
        while (r < n)
        {
            int cnt = 0;
            if (a[r] & 1)
            {
                while (true)
                {
                    if ((a[r] % 2 == 0) || (r >= n))
                    {
                        break;
                    }
                    cnt++;
                    r++;
                }
                seg.push_back(cnt);
            }
            else
                r++;
        }
        for (int val : seg)
        {
            totalSeg -= (1LL*(val * (val + 1)) / 2);
        }
        sort(seg.begin(), seg.end());
        if (!seg.empty())
        {
            int mxSeg = seg.back();
            int mid = mxSeg / 2;
            if (mxSeg & 1)
            {
                mid++;
                totalSeg += 1LL * (mid * (mid));
            }
            else
            {
                totalSeg += (1LL * (mid * (mid + 1)));
            }
        }
        cout << totalSeg << nl;
    }
    return 0;
}