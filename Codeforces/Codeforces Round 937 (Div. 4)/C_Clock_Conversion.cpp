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
        string s;
        cin >> s;

        int time = 0;
        for (int i = 0; i < 2; i++)
        {
            time = time * 10 + (s[i] - 48);
        }
        if(time == 0){
            cout<<"12"<<s.substr(2,5)<<" AM\n";
        }
        else if (time < 12)
        {
            cout << s << " "
                 << "AM\n";
        }
        else if (time == 12)
        {

            cout << s << " "
                 << "PM\n";
        }
        else{
            time-=12;
            if(time < 10){
                cout <<"0"<<time<< s.substr(2,5)<< " "
                     << "PM\n";
                    
            }
            else{
                cout << time;
                for (int i = 2; i < 5; i++)
                {
                    cout << s[i];
                }
                cout << " "
                     << "PM\n";
            }
            
        }
    }
    return 0;
}