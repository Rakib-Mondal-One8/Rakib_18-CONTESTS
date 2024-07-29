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
        int cnt = 0;
        loop(i, 1, 5)
        {
            int val;
            cin >> val;
            if (val == 1)
                cnt++;
        }
        if (cnt >= 4)
        {
            Yes;
        }
        else
            No;
    }
    return 0;
}