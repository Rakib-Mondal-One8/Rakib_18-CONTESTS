#include<bits/stdc++.h>
using namespace std;

int main()
{   ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin>>t;
    
    while(t--)
    {
       int n,x;
       cin>>n>>x;

    
       int ans = (n+x)+(abs(x-n)-1);
       cout<<ans<<'\n';
    }
    return 0;
}