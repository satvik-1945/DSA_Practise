#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n ;
    cin >> n;
    string str;
    cin >>str;
    string ans = "";
    for(int i = 0 ;i < str.size() ; i++ )
    {
        ans+=str[i];
        ans+=str[i];
    }
    cout<<ans<<endl;
}