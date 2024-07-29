#include <bits/stdc++.h>
typedef long long ll;
#define Yes cout << "YES" << '\n'
#define No cout << "NO" << '\n'
#define nl '\n';
#define loop(i, s, n) for (int i = s; i <= n; i++)
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
        string s;
        cin >> n >> s;
        vector<int> ans;

        int prev = 0;
        for (int i = 0; i < n - 1; i += 2)
        {
            if (s[i] != s[i + 1])
            {
                if (prev != (s[i] - '0'))
                {
                    ans.push_back(i);
                    prev = (s[i] - '0');
                }
                else
                {
                    ans.push_back(i + 1);
                    prev = (s[i + 1] - '0');
                }
            }
        }
        cout << ans.size() << nl;
        while (!ans.empty())
        {
            cout << ans.back() + 1 << " ";
            ans.pop_back();
        }
        cout << nl;
    }

    return 0;
}