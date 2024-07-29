#include <bits/stdc++.h>
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
        int target, total = 0;
        cin >> target;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            total += a[i];
        }
        if (target > total)
        {
            cout << "-1\n";
        }
        else
        {
            int l = 0, r = 0;
            int cnt = 0;
            int mxlen = 0;
            while (r < n)
            {
                while (r < n && cnt+a[r] <= target)
                {
                    cnt += a[r];
                    r++;
                }
                mxlen = max(mxlen, (r - l));
                while (l < r && cnt >= target)
                {
                    cnt -= a[l];
                    l++;
                }
            }
            cout << (n - mxlen) << '\n';
        }
    }
    return 0;
}