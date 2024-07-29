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
        cin >> n;

        int om = 0;
        int cnt = 0;
        int addy = 0;

        loop(i, 0, n - 1)
        {
            int x;
            cin >> x;

            if (x != 0)
                cnt++;
            else
                cnt = 0;
            om = max(om, cnt);
        }
        cnt = 0;
        loop(i, 0, n - 1)
        {
            int x;
            cin >> x;

            if (x != 0)
                cnt++;
            else
                cnt = 0;
            addy = max(addy, cnt);
        }
        if (om > addy)
        {
            cout << "Om" << nl;
        }
        else if (om < addy)
        {

            cout << "Addy" << nl;
        }
        else
            cout << "Draw" << nl;
    }
    return 0;
}