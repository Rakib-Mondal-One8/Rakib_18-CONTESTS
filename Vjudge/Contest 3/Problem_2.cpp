#include<bits/stdc++.h>
#define ll long long
#define yes cout<<"YES"<<
#define no cout<<"NO"<<
#define nline '\n';
#define loop(i,s,n) for(int i=s;i<=n;i++)
using namespace std;
int main()
{   ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin>>t;
    
    while(t--)
    {
       int a,b,c;
       cin>>a>>b>>c;

       if((a* b) <= (c*24*60))
       yes nline
       else
        no nline
    }
    return 0;
}