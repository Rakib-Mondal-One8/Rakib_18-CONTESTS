#include <bits/stdc++.h>
typedef long long ll;
#define Yes cout << "YES" << '\n'
#define No cout << "NO" << '\n'
#define nl '\n';
#define loop(i, s, n) for (int i = s; i <= n; i++)
using namespace std;
int rev(int a)
{
    int newNum = 0;
    while (a > 0)
    {
        int lastDigit = a % 10;
        newNum = (newNum * 10) + lastDigit;
        a /= 10;
    }
    return newNum;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        int a, b;
        cin >> a >> b;

        if (a > b)
            Yes;
        else if (rev(a) > b)
            Yes;
        else if (rev(a) > rev(b))
            Yes;
        else if (a > rev(b))
            Yes;
        else
            No;
    }
    return 0;
}