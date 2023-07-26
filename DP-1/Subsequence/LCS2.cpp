#include<bits/stdc++.h>
using namespace std;

string helper(int n , int m, string &s1, string &s2,vector<vector<string>>&dp )
{
    string count = "";
    if(n < 0 || m<0)
    {
        return count;        
    }
    if(dp[n][m]!="")
    {
        return dp[n][m];
    }
    if(s1[n] == s2[m])
    {
        dp[n][m] = helper(n-1,m-1,s1,s2,dp) + s1[n];
    } 
    else    
    {
        // dp[n][m] += max( helper(n,m-1,s1,s2,dp), helper(n-1,m,s1,s2,dp));
        // if(dp[n][   ])
        string l1 = helper(n,m-1,s1,s2,dp);
        string l2 = helper(n-1,m,s1,s2,dp);

        if(l1.size() > l2.size())
        {
            dp[n][m] = l1;
        }
        else 
            dp[n][m] = l2;
    }
    return dp[n][m];

}


int main()
{
    string s1;
    string s2;
    cin >> s1 >> s2;
    vector<vector<string>>dp(s1.size(),(vector<string> (s2.size())));
    
    int n = s1.size();
    int m = s2.size();
    string temp = "";
    string count = helper(n-1,m-1,s1,s2,dp);
    cout<<count;
}