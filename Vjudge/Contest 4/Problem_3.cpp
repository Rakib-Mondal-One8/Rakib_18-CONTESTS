// #include <bits/stdc++.h>
// typedef long long ll;
// #define Yes cout << "YES" << '\n'
// #define No cout << "NO" << '\n'
// #define nl '\n';
// #define loop(i, s, n) for (int i = s; i <= n; i++)
// using namespace std;
// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(NULL);

//     int t;
//     cin >> t;

//     while (t--)
//     {
//         int n, k, lan;
//         cin >> n >> k >> lan;

//         vector<int> l1, l2, l3, l4, l5;
//         loop(i, 0, n - 1)
//         {
//             int x;
//             cin >> x;
//             int l;
//             cin >> l;
//             if (l == 1)
//                 l1.push_back(x);
//             else if (l == 2)
//             {
//                 l2.push_back(x);
//             }
//             else if (l == 3)
//                 l3.push_back(x);
//             else if (l == 4)
//                 l4.push_back(x);
//             else
//             {
//                 l5.push_back(x);
//             }
//         }
//         sort(l1.begin(), l1.end());
//         sort(l2.begin(), l2.end());
//         sort(l3.begin(), l3.end());
//         sort(l4.begin(), l4.end());
//         sort(l5.begin(), l5.end());
//         int longest = 0;
//         if (lan == 1)
//         {
//             loop(i, 1, k)
//             {
//                 longest += l1.back();
//                 l1.pop_back();
//             }
//         }
//         else if (lan == 2)
//         {
//             loop(i, 1, k)
//             {
//                 longest += l2.back();
//                 l2.pop_back();
//             }
//         }
//         else if (lan == 3)
//         {
//             loop(i, 1, k)
//             {
//                 longest += l3.back();
//                 l3.pop_back();
//             }
//         }
//         else if (lan == 4)
//         {
//             loop(i, 1, k)
//             {
//                 longest += l4.back();
//                 l4.pop_back();
//             }
//         }
//         else
//         {
//             loop(i, 1, k)
//             {
//                 longest += l5.back();
//                 l5.pop_back();
//             }
//         }
//         cout << longest << nl;
//     }
//     return 0;
// }

#include <bits/stdc++.h>
typedef long long ll;
#define Yes cout << "YES" << '\n'
#define No cout << "NO" << '\n'
#define nl '\n'
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
        int n, k, lan;
        cin >> n >> k >> lan;

        vector<int> l1, l2, l3, l4, l5;
        loop(i, 0, n - 1)
        {
            int x;
            cin >> x;
            int l;
            cin >> l;
            if (l == 1)
                l1.push_back(x);
            else if (l == 2)
            {
                l2.push_back(x);
            }
            else if (l == 3)
                l3.push_back(x);
            else if (l == 4)
                l4.push_back(x);
            else
            {
                l5.push_back(x);
            }
        }
        sort(l1.begin(), l1.end());
        sort(l2.begin(), l2.end());
        sort(l3.begin(), l3.end());
        sort(l4.begin(), l4.end());
        sort(l5.begin(), l5.end());
        int longest = 0;
        if (lan == 1)
        {
            if (!l1.empty() && l1.size() >= k)
            {
                loop(i, 1, k)
                {
                    longest += l1.back();
                    l1.pop_back();
                }
            }
            else
            {
                longest = -1;
            }
        }
        else if (lan == 2)
        {
            if (!l2.empty() && l2.size() >= k)
            {
                loop(i, 1, k)
                {
                    longest += l2.back();
                    l2.pop_back();
                }
            }
            else
            {
                longest = -1;
            }
        }
        else if (lan == 3)
        {
            if (!l3.empty() && l3.size() >= k)
            {
                loop(i, 1, k)
                {
                    longest += l3.back();
                    l3.pop_back();
                }
            }
            else
            {
                longest = -1;
            }
        }
        else if (lan == 4)
        {
            if (!l4.empty() && l4.size() >= k)
            {
                loop(i, 1, k)
                {
                    longest += l4.back();
                    l4.pop_back();
                }
            }
            else
            {
                longest = -1;
            }
        }
        else
        {
            if (!l5.empty() && l5.size() >= k)
            {
                loop(i, 1, k)
                {
                    longest += l5.back();
                    l5.pop_back();
                }
            }
            else
            {
                longest = -1;
            }
        }
        cout << longest << nl;
    }
    return 0;
}
