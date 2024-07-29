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
        string s;
        cin >> s;

        vector<int> pref(n + 1), suff(n + 2);
        for (int i = 1; i <= n; i++)
        {
            pref[i] = pref[i - 1] + (s[i - 1] - '0');
        }
        for (int i = n; i >= 1; i--)
        {
            suff[i] = suff[i + 1] + (s[i - 1] - '0');
        }
        double mid = n / 2.0, diff;
        int mn = INT_MAX;
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            int zero = i - pref[i];
            int one = suff[i+1];
            int left, right;
            left = ceil(i * 1.0 / 2);
            right = ceil((n - i) * 1.0 / 2);

            if (zero >= left && one >= right)
            {
                diff = abs(mid - i);
                if (diff < mn)
                {
                    mn = diff;
                    ans = i;
                }
            }
        }
        int total_one = pref[n], half = (n * 1.0 / 2);
        if (mid <= mn && total_one >= half)
        {
            ans = 0;
        }
        cout << ans << '\n';
    }
    return 0;
}