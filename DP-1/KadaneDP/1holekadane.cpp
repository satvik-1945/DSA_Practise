#include<bits/stdc++.h>

using namespace std;

int NormalMaxSum(vector<int> &arr, int n,vector<int> &dp)
{   
    dp[0] = arr[0];
    int res = arr[0];
    for (int i = 1; i < n; i++)
    {
        dp[i]= max(dp[i-1] + arr[i], arr[i]);
        res = max(dp[i], res);
    }
    return res;
}
int main()
{
    int n ;
    cin>> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++)  
    {
        cin>> arr[i];
    }
    vector<int>dp_LtR(n);
    vector<int>dp_RtL(n);
    int max_LtR = NormalMaxSum(arr,n, dp_LtR);
    reverse(arr.begin(),arr.end());
    int max_RtL = NormalMaxSum(arr,n, dp_RtL);
    reverse(arr.begin(),arr.end());
    reverse(dp_RtL.begin(),dp_RtL.end());
    int max_ = INT_MIN;
    // int max_ = max(dp_LtR[n-1],dp_RtL[1]);//calculating the case if the extreme left or right value is deleted.
    max_ = max(max_,max_RtL); // just checking if there is any need to delte any values or not
    for(int i = 1 ; i< n-1 ; i++)
    {
        max_= max(dp_LtR[i-1] + dp_RtL[i+1], max_);
    }
    cout<<max_<<endl;
}