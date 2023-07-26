#include <bits/stdc++.h>
using namespace std;

int main() {

  int N ;
  cin>> N;
  vector<long long> arr(N);
  for(int i=0 ; i< N ; i++)
  {
    cin>> arr[i];
  }
  sort(arr.begin(), arr.end());
//   for(int i=0 ; i< N ; i++)
//   {
//     cout<< arr[i]<<" ";
//   }
  int max_till_now =1 ;
  int max_ending_here = 1;
  for(int i=1; i< N ; i++)  
  {
    // max_ending_here = 1
    if(arr[i] == arr[i-1] + 1)
    {
        max_ending_here++;
        max_till_now = max(max_ending_here,max_till_now);
        // cout<<max_till_now<<endl;
    }
    else if(arr[i] == arr[i-1])
    {
        continue;
    }
    else
    {
        max_ending_here=1;
    }
  }
  // if(N == 1)
  // {
  //   cout<<max_ending_here;
  // }
  // else
    cout<<max_till_now;
  return 0;

}