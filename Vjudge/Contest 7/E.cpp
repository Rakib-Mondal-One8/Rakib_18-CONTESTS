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
        int n, q;
        cin >> n >> q;

        vector<int> a(n + 1);
        vector<pair<int, int>> seg2;
        loop(i, 1, n)
        {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        map<int, int> seg;
        while (q--)
        {
            int l, r;
            cin >> l >> r;
            for (int i = l; i <= r; i++)
            {
                seg[i]++;
            }
        }
        for (auto it : seg)
        {
            seg2.push_back({it.second, it.first});
        }
        sort(seg2.rbegin(), seg2.rend());
        ll ans = 0;
        vector<int> res(n + 1);
        for (auto val : seg2)
        {
            // cout << val.first << " " << val.second << nl;
            res[val.second] = a.back();
            ans += ((val.first) * a.back());
            a.pop_back();
        }
        loop(i, 1, n)
        {
            if (res[i] == 0)
            {
                res[i] = a.back();
                a.pop_back();
            }
        }
        cout << ans << nl;
        loop(i, 1, n)
        {
            cout << res[i] << " ";
        }
        cout << nl;
    }
    return 0;
}