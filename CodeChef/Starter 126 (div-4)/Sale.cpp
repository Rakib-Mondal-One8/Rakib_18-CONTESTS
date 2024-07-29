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

        vector<long long > v(n);
        for(int i=0;i<n;i++)
        {
            cin>>v[i];
        }
        long long mxSale = 0;
        long long prevSale = 0;
        for(int i=0;i<n;i++)
        {
            long long sale = 0;
            sale+= (prevSale+(v[i]*2));
            mxSale = max(mxSale,sale);
            prevSale+=v[i];
        }
        cout<<mxSale<<'\n';
    }
    return 0;
}