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
        int n, k;
        cin >> n >> k;

        vector<int> v(n);
        int chocolates = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            chocolates += v[i];
        }

        if (chocolates >= n && (chocolates / n) <= k)
        {
            if (chocolates == n || (chocolates / n) % 2 == 0)
                cout << "YES\n";
            else
                cout << "NO\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
    return 0;
}
