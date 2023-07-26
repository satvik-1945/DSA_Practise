#include <bits/stdc++.h>
using namespace std;

signed main()
{
    int test;
    cin >> test;

    while (test--)
    {
        int n ;
        cin>> n;
        vector<int> arr(n);
        vector<int> sol(n);

        for(int i = 0; i < n; i++)
        {
            cin>>   arr[i];
            sol[i] = arr[i];
        } 
        sort(sol.begin(), sol.end());
        int i = 0;
        int j = n-1;
        int sum = 0;
        while(i<=j)
        {
            sum += sol[j] - sol[i];
            i++;
            j--;
        }
        cout<<sum<<endl;
    }
}
// It is guaranteed that the sum of n
// �
//  for all test cases does not exceed 2⋅105
// 2
// ⋅
// 10
// 5
// .