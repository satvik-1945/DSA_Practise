#include<bits/stdc++.h>
using namespace std;
#define int long long int
bool isPalindrome(const string& str) {
    string reversed = str;
    reverse(reversed.begin(), reversed.end());
    return (str == reversed);
}
signed main()
{
    int n ;
    cin>> n ;
    vector<string> str(n);
    for(int i=0; i<n; i++)
    {
        cin>> str[i];
    }
    string temp1,temp2;
    int flag = 0;
    for(int i=0; i<n-1; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            temp1 = str[i] + str[j];
            temp2 = str[j] + str[i];
            if(isPalindrome(temp1)or isPalindrome(temp2))
            {
                flag = 1;
                break;
            }
        }
        if(flag == 1)
        break;
    }
    if(flag == 1)
        cout<<"Yes";
    else
        cout<<"No";
}