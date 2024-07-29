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
        int n, m;
        string a, b;
        cin >> n >> m;
        cin >> a >> b;

        int k = 0;
        for (int i = 0; i < m; i++)
        {
            if (a[k] == b[i])
                k++;
        }

        cout << k << nl;
    }
    return 0;
}