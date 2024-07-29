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
        int a, b;
        cin >> a >> b;

        if (a - b >= 10)
        {
            cout << "0\n";
        }
        else
        {
            if ((b + 10) - a <= 2 || (b + 10) - a <= 3)
            {
                cout << "1\n";
            }
            else
            {
                int req1 = (10 - (a - b) + 1) / 2;
                int req2 = (10 - (a - b) + 1) / 3;
                cout << min(req1, req2) << '\n';
            }
        }
    }
    return 0;
}
