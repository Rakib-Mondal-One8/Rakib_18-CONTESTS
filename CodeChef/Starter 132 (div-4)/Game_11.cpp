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
        int n, m;
        cin >> n >> m;

        vector<int> bat, bowl;
        loop(i, 0, n - 1)
        {
            int val;
            cin >> val;
            bat.push_back(val);
        }
        loop(i, 0, m - 1)
        {
            int val;
            cin >> val;
            bowl.push_back(val);
        }
        sort(bat.begin(), bat.end());
        sort(bowl.begin(), bowl.end());
        ll skills = 0;

        if (n >= 4 && m >= 4 && n + m >= 11)
        {
            loop(i, 1, 4)
            {
                skills += bat.back();
                bat.pop_back();
            }
            loop(i, 1, 4)
            {
                skills += bowl.back();
                bowl.pop_back();
            }

            loop(i, 1, 3)
            {
                if (!bat.empty() && !bowl.empty())
                {
                    if (bat.back() > bowl.back())
                    {
                        skills += bat.back();
                        bat.pop_back();
                    }
                    else
                    {
                        skills += bowl.back();
                        bowl.pop_back();
                    }
                }
                else if (!bowl.empty())
                {
                    skills += bowl.back();
                    bowl.pop_back();
                }
                else
                {
                    skills += bat.back();
                    bat.pop_back();
                }
            }
            cout << skills << nl;
        }
        else
            cout << -1 << nl;
    }
    return 0;
}