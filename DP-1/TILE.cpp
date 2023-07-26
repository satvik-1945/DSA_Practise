#include <bits/stdc++.h>
using namespace std;
#define int long long int

int helper(int n, vector<int>& memo)
{
    if (n <= 3)
    {
        return n;
    }
    else if(memo[n] == -1)
    {
        memo[n] = (helper(n-1, memo)%1000000007 + helper(n-2, memo)%1000000007)%1000000007;
    }
    return memo[n];
}

signed main()
{
    int nu;
    cin >> nu;
    vector<int> memo(nu+1, -1);
    int res = helper(nu, memo);
    cout << res;
    return 0;
}
