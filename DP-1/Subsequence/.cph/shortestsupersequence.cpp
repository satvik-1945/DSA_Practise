#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;
void LCS(string &s1, string &s2 , int n , int m)
{
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else 
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            
        }
    }
}

int main() 
{
    string s1, s2;
    cin >> s1 >>s2;
    int n = s1.size();
    int m = s2.size();
    
    dp.resize(n + 1, vector<int>(m + 1, 0));   
    LCS(s1,s2,n,m);

    int l = dp[n][m] ;
    cout<<n + m -l;
    return 0;
}
