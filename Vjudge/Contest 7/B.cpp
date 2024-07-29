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
        int n, k;
        cin >> n >> k;
        string l, key;
        cin >> l >> key;

        int lft = 0, rgt = 0;
        int ans = INT_MAX;
        string tmp = "";
        while (rgt < n)
        {
            tmp += l[rgt];
            if (tmp.size() == k)
            {
                int steps = 0;
                for (int i = 0; i < k; i++)
                {
                    int v1 = tmp[i] - '0';
                    int v2 = key[i] - '0';
                    int s1, s2;
                    if (v1 == v2)
                    {
                        s1 = 0;
                        s2 = 0;
                    }
                    else if (v2 > v1)
                    {
                        s1 = (v2 - v1);
                        s2 = (9 - v2 + 1) + v1;
                    }
                    else
                    {
                        s1 = (v1 - v2);
                        s2 = (9 - v1 + 1) + v2;
                    }
                    steps += min(s1, s2);
                }
                ans = min(ans, steps);
                tmp.erase(0, 1);
                lft += 1;
            }
            rgt++;
        }
        cout << ans << nl;
    }
    return 0;
}