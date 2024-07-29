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

        int round = n/2;
        int ans = 0;
        for(int i=1;i<=round;i++)
        {
            ans+=(2*6);
            ans++;
        }
        if(n%2 == 1)
            ans+=6;
        cout<<ans<<'\n';
    }
    return 0;
}