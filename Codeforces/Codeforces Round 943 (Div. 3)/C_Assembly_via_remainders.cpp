#include <bits/stdc++.h>
typedef long long ll;
#define Yes cout << "YES" << '\n'
#define No cout << "NO" << '\n'
#define nl '\n';
#define loop(i, s, n) for (ll i = s; i <= n; i++)
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
        vector<int> x(n - 1);
        loop(i, 0, n - 2)
        {
            cin >> x[i];
        }
        vector<int> a(n);
        int mx = 1e9;
        a[n - 1] = x[n - 2];
        a[n - 2] = mx;
        for (int i = n - 3; i >= 0; i--)
        {
            mx-=x[i];
            a[i] = mx;
        }
        loop(i, 0, n - 1)
        {
            cout << a[i] << " ";
        }
        cout << nl;
    }
    return 0;
}