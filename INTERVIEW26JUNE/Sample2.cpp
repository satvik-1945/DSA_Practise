#include<bits/stdc++.h>
using namespace std;

#define int long long int

signed main()
{
    int n ;
    cin>> n;
    vector<int> v(n+1 , -1);
    vector<int> dp(n+1,0);
    for(int i = 0 ; i< n  ; i++)
    {
        cin>> v[i] ;
        if(v[i] ==  1)
            dp[1] += 1;
    }
    int que;
    cin>> que;
    sort(v.begin(), v.end());
    int k = 2;
    for(int i= 0 ; i< n;i++)
    {
        if(v[i]> k)
        {
            k++;
        }
        if(dp[k] == 0)
            dp[k] += dp[k-1] ;
        if(v[i]<= k)
        {
            dp[k] += v[i] ;
        }
    }
    // cout<<dp []
    for(int i = 0 ; i< que ; i++)
    {
        int l , r;
        cin>>l>>r;
        cout<<dp[r] - dp[l-1]<<endl;
    }

}