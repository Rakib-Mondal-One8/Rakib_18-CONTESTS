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
        int n, x;
        cin >> n >> x;

        if ((n + x) % 2 == 0)
        {
            cout << "YES\n";
        }
        else
            cout << "NO\n";
    }
    return 0;
}