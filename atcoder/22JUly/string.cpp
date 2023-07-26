#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>> n;
    string s;
    cin>> s;
    unordered_map<char,int> mp;
    int i;
    for(i= 0; i< n; i++)
    {
        if(mp.size()==3)
        {
            break;
        }
        mp[s[i]]++;
    }

    cout<<i<<endl;

    return 0;
}