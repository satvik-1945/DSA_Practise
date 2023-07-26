#include <bits/stdc++.h>
using namespace std;

int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        int n;
        cin >> n;
        vector<int> robo(n);
        for (int i = 0; i < n; i++)
        {
            cin >> robo[i];
        }
        vector<int> ans(101, 0);
        for (int i = 0; i < n; i++)
        {
            ans[robo[i]]++;
        }
        
        int flag = 0;
        int sum = ans[0];
        for (int i = 1; i < 101; i++)
        {
            if (ans[i] > ans[i-1] or (ans[i-1] != 0 and i > n))
            {
                flag = 1;
                break;
            }
            sum += ans[i];
        }
        
        if (flag == 0 and sum == n)
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
