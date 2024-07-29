#include<bits/stdc++.h>
using namespace std;

int main()
{   ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;

        vector<int> v(n);
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            cin>>v[i];
        }
        for(int i=0;i<n;i++)
        {
            if (i < n - 1 && v[i] == i + 1)
            {
                swap(v[i],v[i+1]);
                ans++;
            }
            if(i == n-1 && v[i] == i+1)
            {
                ans++;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}