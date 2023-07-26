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
        int sum = n;

        while (n >= 1)
        {
            sum += n / 2;
            n = n / 2;
        }
        cout<<sum<<endl;
    }
}