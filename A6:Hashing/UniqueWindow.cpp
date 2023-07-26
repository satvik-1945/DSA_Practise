#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, k;
    cin>> N>> k;;
    vector<int> arr(N);
    for(int i = 0; i < N; i++)
    {
        cin>> arr[i];
        
    }
    // arr is initialized
    int distinct = 0;
    unordered_map<int,int> mp;
    for(int i = 0; i < k; i++)
    {
        mp[arr[i]]++;
    }
        cout<<mp.size()<<" " ;
        distinct = mp.size();
        
    for(int i = k ; i< N; i++)
    {
        mp[arr[i-k]]--;
        if(mp[arr[i-k]]==0)
          distinct--;
        if(mp[arr[i]] == 0)
          distinct ++;
        mp[arr[i]]++;
        cout<<distinct<<" " ;
    }
    return 0;

}