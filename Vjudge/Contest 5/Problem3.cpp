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
        int n, a;
        cin >> n >> a;

        string s;
        cin >> s;
        int tmp = 1;
        int cnt1 = 1;
        char prev = s[0];
        loop(i, 1, n - 1)
        {
            if (prev == s[i])
                tmp++;
            else
            {

                prev = s[i];
                tmp = 1;
            }
            cnt1 = max(cnt1, tmp);
        }
        cout << cnt1 << " ";
        int cnt2 = cnt1;
        while (a--)
        {
            char c;
            cin >> c;

            if (prev == c)
                tmp++;
            else
            {
                tmp = 1;
                prev = c;
            }
            cnt2 = max(cnt2, tmp);
            cout << cnt2 << " ";
        }
        cout << nl;
    }
    return 0;
}