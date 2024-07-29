//Method - 1
/*
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
        int n;
        cin >> n;
        vector<int> a(n);
        loop(i, 0, n - 1)
        {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        int l = 0, r = n - 1;
        ll ans = 0;
        while (l <= r)
        {
            if (l != r)
                ans += (a[r] - a[l]);
            else
                ans += a[r];
            l++;
            r--;
        }
        cout << ans << nl;
    }
    return 0;
}
*/

//Method - 2
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        sort(a, a + n);
        int left = 0, right = n - 1;
        int sum = 0;
        for (int i = 1; i <= n; i++)
        {
            if (i % 2)
            {
                sum += a[right];
                right--;
            }
            else
            {
                sum -= a[left];
                left++;
            }
        }
        cout << sum << "\n";
    }
}
