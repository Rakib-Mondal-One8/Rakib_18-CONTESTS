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
        int n;
        cin >> n;

        string a;
        string tmp;

        cin >> a;
        tmp = a;
        bool flag = false;

        for (int i = 0; i < n - 2; i++)
        {
            string prev = tmp;
            tmp.replace(i, 3, "100");
            // cout<<tmp<<nline
            int cnt = 0;
            for (int j = i; j <i+3; j++)
            {
                if ((prev[j] - '0') > (tmp[j] - '0'))
                    cnt++;

                else if ((prev[j] - '0') < (tmp[j] - '0'))
                    cnt--;
            }
            if (cnt >= 1)
            {
                flag = true;
                // cout << tmp << nline
            }
            else if (cnt < 1)
            {
                tmp = prev;
            }
        }
        if (!flag)

            cout << a << nline
        else
            cout<< tmp << nline
    }
    return 0;
}