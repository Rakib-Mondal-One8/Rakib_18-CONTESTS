#include <bits/stdc++.h>
typedef long long ll;
#define Yes cout << "YES" << '\n'
#define No cout << "NO" << '\n'
#define nl '\n';
#define for(i, s, n) for (int i = s; i <= n; i++)
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        ll n, k;
        cin >> n >> k;

        vector<ll> a(n);
        for (i, 0, n - 1)
        {
            cin >> a[i];
        }
        ll l = 0, r = n - 1;
        vector<ll> tmp(a);
        while (k > 0 && l < r)
        {

            ll mn = min(tmp[l], tmp[r]);
            if ((2 * mn) <= k)
            {
                tmp[l] -= mn;
                tmp[r] -= mn;
                k -= (2 * mn);
            }
            else
            {
                if(k>0)
               {
                   tmp[l] -= ceil(k * 1.0 / 2 * 1.0);
                   tmp[r] -= (k / 2);
                   k = 0;
               }
            }
            if (tmp[l] == 0)
            {
                l++;
            }
            if (tmp[r] == 0)
            {
                r--;
            }
        }
        if (k > 0 && l == r)
        {
            tmp[l] -= k;
            if (tmp[l] < 0)
                tmp[l] = 0;
        }
        ll cnt = 0;
        for (i, 0, n - 1)
        {
            // cout << tmp[i] << " ";
            if (tmp[i] == 0)
            {
                cnt++;
            }
        }
        // cout << nl;
        cout << cnt << nl
    }
    return 0;
}