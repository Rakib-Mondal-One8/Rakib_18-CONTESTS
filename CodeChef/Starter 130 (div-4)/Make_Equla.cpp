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

        vector<int> a(n);
        int mn = INT_MAX;
        loop(i, 0, n - 1)
        {
            cin >> a[i];
            mn = min(mn, a[i]);
        }
        if (a[0] == mn && a[0] == a[n - 1])
        {
            Yes;
        }
        else
            No;
    }
    return 0;
}