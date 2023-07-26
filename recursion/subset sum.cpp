#include <bits/stdc++.h>
using namespace std;
// #define long long as ll;
long long  sum_arr(vector<long long> temp)
{
     long long sum = 0;
    for (int i = 0; i < temp.size(); i++)
    {
        sum += temp[i];
    }
    return sum;
}
void helper(vector<long long >& arr, int& n , long long & sum ,int index,vector<long long> & temp ,long long & min_)
{
    if(index == arr.size())
    {
       long long  l = sum_arr(temp);  
       long long  r = sum - l;
       min_ = min(min_, abs(l-r));
       return ;
    }
    temp.push_back(arr[index]);
    helper(arr,n , sum ,index+1, temp, min_);
    temp.pop_back();
    helper(arr,n , sum ,index+1, temp, min_);
}
int main() {

    int n ;
    cin>> n;
    vector<long long > arr(n);
    long long  sum = 0;
    for(int i=0; i<n; i++)
    {
        cin>>arr[i] ;
        sum += arr[i] ;
    }
    vector<long long > temp;
    long long  min_ = INT_MAX;
    helper(arr, n, sum , 0, temp, min_);
    cout<<min_;
    

  return 0;

}