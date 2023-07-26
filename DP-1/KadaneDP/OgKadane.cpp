#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>> n;
    vector<int>arr(n+1);

    for(int i = 0 ; i< n ; i++)
    {
        cin >>arr[i];
    }  
    vector<int> dp(n+1);
    dp[0] = arr[0];
    int max_ = arr[0];
    for(int i = 1 ; i< n ; i++)
    {
        dp[i] = max(dp[i-1] + arr[i] ,arr[i]);
        max_ = max(max_,dp[i]);
    }  
    cout<<max_;    
    return 0;       
}