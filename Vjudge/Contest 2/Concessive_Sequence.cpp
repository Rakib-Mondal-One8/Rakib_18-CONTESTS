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

        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        for(int j=0;j<n;j++){
            for (int i = 1; i < n - 1; i++)
            {
                if ((v[i] >= v[i - 1] && v[i] <= v[i + 1]) || v[i] <= v[i - 1] && v[i] >= v[i + 1])
                {
                    swap(v[i], v[i + 1]);
                }
            }
        }
      
        bool flag = true;
        for (int i = 1; i < n - 1; i++)
        {
            if ((v[i] >= v[i - 1] && v[i] <= v[i + 1]) || v[i] <= v[i - 1] && v[i] >= v[i + 1])
            {
                flag = false;
                break;
            }
        }
        if (flag == false)
        {
            cout << "-1\n";
        }
        else
        {
            for (int val : v)
            {
                cout << val << " ";
            }
            cout << '\n';
        }
    }
    return 0;
}