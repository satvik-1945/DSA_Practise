#include <bits/stdc++.h>
using namespace std;
// using ll = long long;
// int n;
// vector<vector<int>> dp;
// ll mod = 1e9 + 7;
// ll f(int i, int pr)
// {
//   if (i == n)
//   {
//     return 1;
//   }
//   if (dp[i][pr] != -1)
//     return dp[i][pr];
//   ll ans = f(i + 1, pr);
//   ans %= mod;
//   if (i % 2 != pr)
//   {
//     ans += f(i + 1, 1 - pr);
//     ans %= mod;
//   }
//   dp[i][pr] = ans;
//   return ans;
// }
// int main()
// {
//   cin >> n;
//   dp = vector<vector<int>>(n, vector<int>(2, -1));
//   cout << (f(0, 0) + f(0, 1) - 2) % mod << endl;
//   return 0;
// }

#define int long long int
vector<vector<int>> dp;
int mod = 1000000007;
int n;
int helper(int i, int prev)
{
  if (i == n)
    return 1;
  if (dp[i][prev] != -1)
  {
    return dp[i][prev];
  }

  int ans = helper(i+1,prev);
  ans%=mod;
  if(i%2 != prev)
  {
    ans+= helper(i + 1, 1- prev);
    ans%=mod;
  }
  dp[i][prev] = ans;
  return dp[i][prev];
}
signed main()
{
  cin >> n;
  dp.resize(n, vector<int>(2, -1));
  cout << helper(0, 0) + helper(0, 1) - 2;
  return 0;
}