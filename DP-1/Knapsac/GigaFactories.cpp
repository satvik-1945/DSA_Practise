#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n, c;
    cin >> n >> c;

    vector<int> val(n);
    vector<int> cost(n);
    for(int i = 0; i < n; i++)
    {
        cin>>cost[i]>>val[i];
    }
    vector<vector<int>> dp(n + 1 , vector<int> (c+1, 0));

    for(int i = 1 ; i<= n ; i++)
    {
        for(int j = 1 ; j<= c ; j++)
        {
            dp [i][j] = dp[i-1][j];
            if(j- cost[i-1]>=0)
                dp[i][j] = max(dp[i][j],val[i-1] + dp[i-1][j- cost[i-1]]);
        }
    }
    cout<< dp[n][c];


    return 0;
}