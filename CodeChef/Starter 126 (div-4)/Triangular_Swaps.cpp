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

        string s;
        cin>>s;
        vector<bool> freq(26,false);
        int distinct = 0;
        for(int i=0;i<n;i++)
        {
            if(freq[s[i]-'a'] == false)
            {
                distinct++;
                freq[s[i]-'a'] = true;
            }
        }
        cout<<distinct<<'\n';
    }
    return 0;
}