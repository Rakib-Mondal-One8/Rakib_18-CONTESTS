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
        int n, x;
        cin >> n >> x;

        int number = n * x;
        int cnt = 0;
        int prev = 0;
        while (number != 0)
        {
            int lastdigit = number % 10;
            cnt++;
            prev = lastdigit;
            number /= 10;
        }
        if(prev != 0 && cnt == 5){
            cout<<"YES\n";
        }
        else
            cout<<"NO\n";
    }
    return 0;
}