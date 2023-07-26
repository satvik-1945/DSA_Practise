#include<bits/stdc++.h>
using namespace std;
#define int long long int

signed main()
{
    int n ;
    cin>> n;
    vector<int> arr(7*n);

    for(int i=0; i <7 * n ; i++)
    {
        cin>> arr[i];
    }
    int sum ;
    vector<int> ans;
    int k = 1;
    int j = 0;
    for(int i = 0; i< n ; i++)
    {
        sum = 0;
        for(int i = 0; i< 7 ; i++)
        {
            // max_ = m
            sum += arr[j];
            j++;
        }
        ans.push_back(sum);
    }
    for(int i =0 ; i< ans.size(); i++)
    {
        cout<< ans[i]<<" ";
    }
}