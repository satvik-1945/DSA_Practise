#include <bits/stdc++.h>
using namespace std;

int main() {

  int N,K;
  cin >> N >> K;
  vector<int> arr(N);
  for (int i = 0; i < N; i++)
  {
    cin >> arr[i];
  }
  queue<int> q;
  int sum = 0;
  int ans= INT_MAX;
  int l;
  int s = 3*N;
  int i = 1;
  while(s--)
  {
    if(K > sum )
    {
        
        if( i< N){
            if(arr[i]<0&& !q.empty())
            {
                l = i;
                sum +=  arr[i];
                // cout<< sum << endl;
                q.push(arr[i]);
                // cout<<" ball "<<sum<<endl;
            }
            else if( arr[i]>0)
            {
                 l = i;
                sum +=  arr[i];
                // cout<< sum << endl;
                q.push(arr[i]);
                // cout<<" ball "<<sum<<endl;
            }
                i++;
        }
        
    }
    // cout<<"sezz"<<sum<<endl;
    else 
    {
        if(q.size() <= ans)
            ans = q.size();
            // cout<<ans<<"s"<<endl;
        q.pop();
        sum -= arr[l];
        l++;

    }
  }
  if(ans == INT_MAX)
    cout<<-1;
  else
    cout<< ans;
  
  

  return 0;

}