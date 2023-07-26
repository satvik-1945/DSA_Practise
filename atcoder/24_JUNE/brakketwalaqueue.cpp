#include <bits/stdc++.h>
using namespace std;

signed main()
{
    int n;
    cin >> n;
    string str;
    cin >> str;
    stack<char> stk;
    // stk.push(str[0]);
    int flag = 0;
    for (int i = 0; i < n; i++)
    {
        if (str[i] == ')')
        {
            if (!stk.empty())
            {
                if (flag > 0)
                {
                    while (stk.top() != '(')
                    {
                        stk.pop();
                    }
                    if (stk.top() == '(')
                    {
                        stk.pop();
                        flag--;
                    }
                }
                else 
                    stk.push(')');
            }
            else
                stk.push(str[i]);
        }
        else
        {
            if (str[i] == '(')
                flag++;
            stk.push(str[i]);
            // flag++;
        }
    }
    string result;
    while (!stk.empty())
    {
        result += stk.top();
        stk.pop();
    }
    reverse(result.begin(), result.end());
    cout << result << endl;
    return 0;
}
