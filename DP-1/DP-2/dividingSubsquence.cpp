#include<bits/stdc++.h>
using namespace std;

// #define int long long int

int main()
{
    int n ;
    cin>> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++)
    {
        cin>> arr[i];
    }
    vector<int> dp(n,1);
    // dp[0] = 1;

    for(int i= 1 ; i < n; i++)
    {
        for(int j = 0 ; j< i ; j++)
        {
            if(arr[i]% arr[j] == 0 )
            {
                dp[i] = max(dp[j] + 1,dp[i]);
            }
        }
    }
    int max_ = 0;
    for(int i = 0 ; i<n ; i++)
    {
       max_ = max(max_,dp[i]);

        // __max_element
    }
    cout<<max_<<endl;
    return 0;
}