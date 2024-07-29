#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{   ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll t;
    cin>>t;

    while(t--)
    {
        ll n;
        cin>>n;

        vector<ll > v(n);
        map<int,int> cnt;
        for(ll i=0;i<n;i++)
        {
            cin>>v[i];
            cnt[v[i]]++;
        }
        long long ans = 0;
        for(int j=n-1;j>=1;j--){
            cnt[v[j]]--;
            int need = 2*v[j];
            for(int i=2;i<=10;i++){
                int x,y;
                x = i+v[j];
                y = i*v[j];

                if(y-x == need){
                    if(cnt[i]>=1){
                        ans+=cnt[i];
                    }
                }
                else if ((y - x) > need) break;
            }
            
        }
        
        cout<<ans<<'\n';
    }
    return 0;
}