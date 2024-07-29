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
        int n, a, b;
        cin >> n >> a >> b;
        int a[n + 1][n + 1];
        int mn = INT_MAX;
        for (int k = 0; k < n; k++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> a[k][j];
                mn = min(mn,a[k][j]);
            }
        }


    }
    return 0;
}