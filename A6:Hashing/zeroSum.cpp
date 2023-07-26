#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<long long >arr(N);
  int flag = 0;
  unordered_map<int,int>mp;
  long long s = 0;

  for(int i = 0; i < N; i++)
  {
    cin >> arr[i];
    s+= arr[i];
    if(mp.find(s) == mp.end())
    {
      mp[s]++;
    }
    else
    {
      cout<<"YES";
      flag = 1;
      break;
    }
    
  }
  if(flag == false)
  {
  cout<<"NO";
  }
  
  return 0;

}