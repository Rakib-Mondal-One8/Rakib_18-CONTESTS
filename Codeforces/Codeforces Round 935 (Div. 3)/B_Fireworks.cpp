#include <bits/stdc++.h>
using namespace std;
void solve()
{
    long long a, b, m;
    cin >> a >> b >> m;
    m++;
    long long ans = (m + a - 1) / a + (m + b - 1) / b;
    cout << ans << '\n';
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long t;
    cin >> t;

    while (t--)
    {
        solve();
    }
    return 0;
}
