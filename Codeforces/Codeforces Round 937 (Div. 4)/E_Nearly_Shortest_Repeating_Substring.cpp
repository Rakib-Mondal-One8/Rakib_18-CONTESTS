#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        string s;
        cin >> s;

        string tmp = s.substr((s.size() / 2),n); 
        // cout<<tmp<<'\n';
        int diff = 0;
        for (int i = 0; i < s.size() / 2; i++)
        {
            if (s[i] != tmp[i])
                diff++;
        }
        if(diff >= 2){
            cout<<s.size()<<'\n';
        }
        else{
            int l=0,r=0;
            string tempo="";
            map<int,int>mp;
            int len = INT_MAX;
            while(r<s.size()){
                tempo+=s[r];
                if(mp.find(s[r]) != mp.end()){
                    len = min(len, r - l);
                    while(l<=mp[s[r]] && mp.find(s[r])!= mp.end()){
                        mp.erase(s[l]);
                        tempo.erase(0,1);
                        l++;
                    }
                }
                
                mp[s[r]] = r;
                r++;
            }
            cout<<len<<'\n';
        }
    }
    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(NULL);

//     int t;
//     cin >> t;

//     while (t--)
//     {
//         int n;
//         cin >> n;

//         string s;
//         cin >> s;

//         string tmp = s.substr((s.size() / 2), n);
//         int diff = 0;
//         for (int i = 0; i < s.size() / 2; i++)
//         {
//             if (s[i] != tmp[i])
//                 diff++;
//         }
//         if (diff >= 2)
//         {
//             cout << s.size() << '\n';
//         }
//         else
//         {
//             int l = 0, r = 0;
//             string tempo = "";
//             map<int, int> mp;
//             int len = 1; // Initialize len to 1
//             while (r < s.size())
//             {
//                 tempo += s[r];
//                 if (mp.find(s[r]) != mp.end())
//                 {
//                     len = max(len, r - l + 1);
//                     while (l <= mp[s[r]])
//                     {
//                         tempo.erase(0, 1); // Fix tempo.erase(0, 1)
//                         l++;
//                     }
//                 }

//                 mp[s[r]] = r; // Store the index of the character
//                 r++;
//             }
//             cout << len-1 << '\n';
//         }
//     }
//     return 0;
// }
