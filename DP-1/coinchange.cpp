#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;

int helper(int sum, vector<int> &s, int n, int i)
{
    if (sum == 0)
    {
        return 1;
    }
    if (sum < 0 || i >= n)
    {
        return 0;
    }
    if (dp[i][sum] != -1)
    {
        return dp[i][sum];
    }
    int count = 0;
    count += helper(sum, s, n, i + 1);
    count += helper(sum - s[i], s, n, i);
    dp[i][sum] = count;
    return count;
}

int main()
{
    int n;
    cin >> n;
    int sum;
    cin >> sum;

    vector<int> s(n);
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }

    dp.resize(n + 1, vector<int>(sum + 1, -1));
    int count = helper(sum, s, n, 0);
    cout << count << endl;
}
