#include <bits/stdc++.h>
using namespace std;
#define int long long int
vector<vector<int>> dp;
int helper(int i,int j , vector<int> & p,int N)
{
    int Y = N +i-j;
    // int res;
    if(i == j) return Y * p[i];
    if(dp[i][j] == -1)
    {
        dp[i][j] = max((helper(i+1,j,p,N)+ p[i]*Y),(helper(i,j-1,p,N)+ p[j]*Y));
    }
    return dp[i][j];
}
signed main()
{
    int n ; 
    cin >> n;
    dp.resize(n+1,vector<int>(n+1,-1));
    vector<int> p(n+1);
    for(int i = 1; i< n+1; i++ )
    { 
        cin >>p[i];
    }
    int N = n;
    int res = helper(1,n,p,N);
    cout<<res;
    return 0;
}