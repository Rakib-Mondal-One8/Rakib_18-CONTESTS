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
        int n;
        cin >> n;

        for (int i = 1; i <= n; i++)
        {
            if (i % 2 != 0)
            {
                for (int l = 1; l <= 2; l++)
                {
                    bool hash = false;
                    bool dot = false;
                    for (int j = 1; j <= n; j++)
                    {
                        if (hash == false)
                        {
                            for (int k = 1; k <= 2; k++)
                            {
                                cout << "#";
                                hash = true;
                                dot = false;
                            }
                        }
                        else if (dot == false)
                        {
                            for (int k = 1; k <= 2; k++)
                            {
                                cout << ".";
                                dot = true;
                                hash = false;
                            }
                        }
                    }
                    cout << '\n';
                }
            }
            else
            {

                for (int l = 1; l <= 2; l++)
                {
                    bool hash = false;
                    bool dot = false;
                    for (int j = 1; j <= n; j++)
                    {
                        if (dot == false)
                        {
                            for (int k = 1; k <= 2; k++)
                            {
                                cout << ".";
                                dot = true;
                                hash = false;
                            }
                        }
                        else if (hash == false)
                        {
                            for (int k = 1; k <= 2; k++)
                            {
                                cout << "#";
                                hash = true;
                                dot = false;
                            }
                        }
                    }
                    cout << '\n';
                }
            }
            // cout<<'\n';
        }
    }
    return 0;
}