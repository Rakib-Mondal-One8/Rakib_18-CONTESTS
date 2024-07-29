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

        int a[n];
        int freq[n+1] = {0};
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            freq[a[i]]++;
        }
        bool f = false;
        for(int i=n;i>=1;i--)
        {
            if(freq[i] >= 3)
            {
                f = true;
                cout<<i<<'\n';
                break;
            }
        }
        if(!f)
            cout<<"-1\n";
        
    }
    return 0;
}