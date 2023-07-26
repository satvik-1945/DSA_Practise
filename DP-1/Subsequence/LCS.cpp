#include<bits/stdc++.h>
using namespace std;

int helper(int n , int m, string &s1, string &s2,vector<vector<int>>&dp )
{
    int count = 0;
    if(n < 0 || m<0)
    {
        return count;        
    }
    if(dp[n][m])
    {
        return dp[n][m];
    }
    if(s1[n] == s2[m])
    {
        dp[n][m] = helper(n-1,m-1,s1,s2,dp) +1;
    } 
    else
    {
        dp[n][m] +=max(helper(n,m-1,s1,s2,dp), helper(n-1,m,s1,s2,dp));
    }
    return dp[n][m];

}


int main()
{
    string s1;
    string s2;
    cin >> s1 >> s2;
    vector<vector<int>>dp(s1.size(),(vector<int> (s2.size())));
    
    int n = s1.size();
    int m = s2.size();
    int cnt = 0;
    int count = helper(n-1,m-1,s1,s2,dp);
    cout<<count;
}