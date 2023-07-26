#include <bits/stdc++.h>
using namespace std;

int main() {

  int c, m, n;
  cin>>c>>m>>n;
  
  int zero[c+1];
  int one[c+1];
  
  for(int i=1; i<=c; i++) {
    string s;
    cin>>s;
    int z=0, o =0;
    for(int j=0; j<s.size(); j++) {
      if(s[j] == '0') z++;
      else o++;
    }
    zero[i] = z;
    one[i] = o;
  }
  
  int dp[c+1][m+1][n+1];
  
  for(int i=0; i<=m; i++) {
    for(int j=0; j<=n; j++) {
      dp[0][i][j] = 0;
    }
  }

    for(int i=1; i<=c; i++) {
      for(int j=0; j<=m; j++) {
        for(int k=0; k<=n; k++) {
          int op1 = dp[i-1][j][k];
          int op2 = (zero[i] <= j && one[i] <= k) ? 1 + dp[i-1][j-zero[i]][k-one[i]] : 0;
          dp[i][j][k] = max(op1, op2);
        }
      }
    }
    cout << dp[c][m][n]; 

}