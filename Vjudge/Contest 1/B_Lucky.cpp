#include<bits/stdc++.h>
using namespace std;

int main()
{   ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        int p1 = 0;
        int i = 0;
        while(i < 3)
        {
            int lastdigit = n%10;
            p1+=lastdigit;
            n/=10;
            i++;
        }
        int p2 = 0;
        while(i < 6)
        {
            int lastdigit = n % 10;
            p2 += lastdigit;
            n /= 10;
            i++;
        }
        if(p1 == p2)
        {
            cout<<"YES\n";
        }
        else
        {
            cout<<"NO\n";
        }
    }
    return 0;
}