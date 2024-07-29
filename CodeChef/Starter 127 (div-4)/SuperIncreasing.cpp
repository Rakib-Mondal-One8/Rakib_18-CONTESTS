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
        int n, k, x;
        cin >> n >> k >> x;

        int prev = (pow(2, k - 1) - 1);

        if (prev < x && k < 30)
        {
            cout << "YES\n";
        }
        else
            cout << "NO\n";
    }
    return 0;
}