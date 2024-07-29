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
        int n, x;
        cin >> n >> x;

        int m = n - 1;
        // if ((m - (n / 2)) < x)
        // {

        //     cout << -1 << nl;
        // }
        // else 
        if (x == 0)
        {
            loop(i, 1, n)
            {
                cout << i << " ";
            }
            cout << nl;
        }
        else
        {
            int v = m - x;
            int req = n - (v - 1);
            if(req > n){

                cout<<"-1"<<nl;
                continue;
            }
            cout << req << " ";
            int val = 1;
            loop(i, 1, n)
            {
                if (val != req)
                    cout << val << " ";
                val++;
            }
            cout << nl;
        }
    }
    return 0;
}
