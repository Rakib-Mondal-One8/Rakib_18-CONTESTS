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

        if (b > a && b > c)
        {
            cout << "PEAK\n";
        }
        else if ((b > a && c > b))
        {
            cout << "STAIR\n";
        }
        else
        {
            cout << "NONE\n";
        }
    }
    return 0;
}