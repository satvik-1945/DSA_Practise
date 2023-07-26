#include<bits/stdc++.h>
using namespace std;

int main()
{
    int test;
    cin>> test;
    while(test--)
    {
        int n;
        cin>> n;
        vector<int> h(n+1);
        vector<int> dp(n+1);
        for(int i = 1 ; i< n+1 ; ++i)
        {
            cin>>h[i];
            dp[i] = h[i];
        }
        dp[1] = h[1];
        for(int i = 2 ; i< n+1 ; ++i)
        {
            for(int j = 1; j< i; j++)
            {
                dp[i] = max((dp[j] + h[i-j]),dp[i]);
            }            
        }
        cout<<dp[n]<<endl;
    }
}