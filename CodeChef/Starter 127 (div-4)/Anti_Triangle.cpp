#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        int n, l;
        cin >> n >> l;

        vector<long long> a(n);
        long long val = l;
        for (int i = 0; i < n; i++)
        {
            a[i] = val;
            val++;
        }
        for (long long val : a)
        {
            cout << val << " ";
        }
        cout << '\n';
    }
    return 0;
}