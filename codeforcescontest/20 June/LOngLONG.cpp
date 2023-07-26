#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
    int test;
    cin >> test;
    while (test--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            sum += abs(arr[i]);
        }
        int count = 0;
        int max_till_now = 0;
        int flag = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] < 0)
            {
                max_till_now++;
                flag = 1;
            }
            else if( arr[i] == 0 and flag == 1 )
            {
                continue;
            }
            else
            {
                if (max_till_now != 0 && flag == 1)
                    count++;
                max_till_now = 0;
                flag = 0;
            }
        }
        if ( flag == 1)
        {
            count++;
        }
        cout << sum << " " << count << endl;
    }
}
