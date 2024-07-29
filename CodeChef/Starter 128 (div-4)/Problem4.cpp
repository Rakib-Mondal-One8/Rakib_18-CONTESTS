#include <bits/stdc++.h>
#define ll long long
#define yes cout << "YES" <<
#define no cout << "NO" <<
#define nline '\n';
#define loop(i, s, n) for (int i = s; i <= n; i++)
using namespace std;
bool is_Possible(vector<ll> &a, int j, ll x)
{
    a[j] += x;
    loop(i, j + 1, a.size() - 1)
    {
        if (a[i - 1] > a[i])
        {
            a[i] += x;
            if (a[i - 1] > a[i])
            {
                return false;
            }
        }
    }
    return true;
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

        ll x = 0;
        // int j = 0;
        // bool break_flag = false;
        bool flag = true;
        bool operation = false;
        loop(i, 1, n - 1)
        {
            if (a[i - 1] > a[i])
            {
                if (operation)
                {
                    flag = false;
                    break;
                }
                flag = is_Possible(a, i, (a[i - 1] - a[i]));
                if (!flag)
                    break;
                operation = true;
            }
        }

        (flag == true) ? cout << "YES\n" : cout << "NO\n";
    }
    return 0;
}
