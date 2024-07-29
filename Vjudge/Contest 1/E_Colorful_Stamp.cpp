#include<bits/stdc++.h>
using namespace std;
// Unsolved
int main()
{   ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;
        string s;
        cin>>s;
        bool f = true;
        if(n == 1)
        {
            cout<<"NO\n";
            continue;
        }
        int W = 0;
        for(int i=0;i<n;i++)
        {
            if(s[i] == W)
                W++;
        }
        if(W==n)
        {
            cout<<"YES\n";
        }
        for(int i=0;i<n-1;i+=2)
        {
            if(s[i] == 'W' || s[i+1] == 'W')
            {
                f = false;
                break;
            }
        }
        if(W==n)
            continue;
        if(f==true)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}