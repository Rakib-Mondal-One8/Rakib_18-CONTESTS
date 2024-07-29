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
        int a, b, c;
        cin >> a >> b >> c;

        int mxUni = c;
        int uni = 0;
        int extro = 0;
        int ans = 0;
        ans += a;

        if (b >= 3)
        {
            ans += b / 3;
            c += b % 3;
            extro += b % 3;
        }
        else if (b != 0)
        {
            c += b;
            extro += b % 3;
        }
        if (c >= 3)
        {
            ans += c / 3;
            // ans++;
            if (c % 3 != 0 && c % 3 <= mxUni)
            {
                ans++;
            }
        }
        else
            uni += c;

        if (uni != 0 && c < 3)
        {
            if (extro == 0)
            {
                cout << ++ans << '\n';
            }
            else
                cout << "-1\n";
        }
        else
            cout << ans << '\n';
    }

    return 0;
}