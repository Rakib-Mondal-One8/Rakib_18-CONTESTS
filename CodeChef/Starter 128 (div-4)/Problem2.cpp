#include <bits/stdc++.h>
#define ll long long
#define yes cout << "YES" <<
#define no cout << "NO" <<
#define nline '\n';
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
        int n, l, r;
        cin >> n >> l >> r;

        vector<int> a(n);
        loop(i, 0, n - 1)
        {
            cin >> a[i];
        }
        int mx = 0;
        int mn = 0;

        int happiness = 0;
        loop(i, 0, n - 1)
        {

            if (a[i] >= l && a[i] <= r)
            {
                happiness++;
                mx = max(mx,happiness);
                // mn = min(mn,happiness);
            }
            else{
                happiness--;
                // mx = max(mx, happiness);
                mn = min(mn, happiness);
            }
        }
        cout << mx<<" "<< mn << nline
    }
    return 0;
}