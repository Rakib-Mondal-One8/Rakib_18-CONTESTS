#include <bits/stdc++.h>
#define ll long long
#define yes cout << "YES" <<
#define no cout << "NO" <<
#define nline '\n';
#define loop(i, s, n) for (int i = s; i <= n; i++)
using namespace std;
bool is_sorted(vector<int> &a)
{

    bool flag = true;
    loop(i, 0, a.size() - 1)
    {
        if (a[i] != i && a[i] >= a[i + 1])
        {
            flag = false;
        }
    }
    return flag;
}
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

        vector<ll> a(n);
        loop(i, 0, n - 1)
        {
            cin >> a[i];
        }
        sort(a.begin(), a.end());

        ll op = 0;
        ll mex = 0;
        loop(i, 0, n - 1)
        {
            if (a[i] == mex)
            {
                mex++;
            }
            else if (a[i] > mex)
            {
                op += (a[i] - mex);
                mex++;
            }
            else
            {
                op += (mex - a[i]);
                mex++;
            }
        }
        cout << op << nline
    }
    return 0;
}

