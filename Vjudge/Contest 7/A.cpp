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
        float n, v1, v2;
        cin >> n >> v1 >> v2;
        float tortoise = (n * 1.0 / v1 * 1.0);
        float hare = (n * 1.0 / v2 * 1.0);
        int speed = tortoise;
        int s1 = tortoise;
        int s2 = hare;
        if (tortoise > float(speed))
            s1 += 1;
        speed = hare;
        if (hare > float(speed))
            s2 += 1;
        cout << (s1 - s2) - 1 << nl;
    }
    return 0;
}