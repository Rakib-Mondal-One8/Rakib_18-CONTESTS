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

        vector<char> a(n);
        vector<char> b(n);
        int chef = 0;
        int chefina = 0;

        loop(i, 0, n - 1)
        {
            cin >> a[i];
        }
        loop(i, 0, n - 1)
        {
            cin >> b[i];
        }

        loop(i, 0, n - 1)
        {
            if (a[i] != b[i])
            {
                if (a[i] == 'R' && b[i] == 'P')
                {
                    chefina++;
                }
                else if (a[i] == 'R' && b[i] == 'S')
                {
                    chef++;
                }
                else if (a[i] == 'S' && b[i] == 'P')
                {
                    chef++;
                }
                else if (a[i] == 'S' && b[i] == 'R')
                {
                    chefina++;
                }
                else if (a[i] == 'P' && b[i] == 'R')
                {
                    chef++;
                }
                else if (a[i] == 'P' && b[i] == 'S')
                {
                    chefina++;
                }
            }
        }
        if (chef > chefina)
        {
            cout << "0\n";
        }
        else if (chef == chefina)
        {
            cout << "1\n";
        }
        else
        {
            cout << (chefina - chef)/2+1 << nline
        }
    }
    return 0;
}