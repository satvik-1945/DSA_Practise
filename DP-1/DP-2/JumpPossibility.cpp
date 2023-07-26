#include <bits/stdc++.h>
using namespace std;

int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        vector<vector<int>> dp(n + 1, vector<int>(k + 1));
        for (int i = 0; i < n + 1; i++)
        {
            dp[i][0] = 1;
        }
        for (int i = 1; i < k + 1; i++)
        {
            dp[0][i] = 0;
        }
        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 1; j < k + 1; j++)
            {
                if(dp[i][j] == j)
                    dp[i][j] =1;
                else if(dp[i-1][j] == 1)
                    dp[i][j] = 1;
                else if(j - v[i-1] >= 0)
                    dp[i][j] = dp[i-1][j-v[i-1]];
            }
        }
        if (dp[n][k] == 1)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}
