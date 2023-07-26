// You are given an array A
// �
//  with N
// �
//  elements. You have to output the array with the elements re-arranged in such a way that the elements with the highest frequency come first. If two elements have the same frequency, then the element which is smaller in value must come first.

// Output the N
// �
//  numbers according to the above rules.  
#include <bits/stdc++.h>
using namespace std;
bool comp(pair<long long , long long >&a,pair<long long , long long >&b)
{
    if(a.second == b.second)
        return a.first < b.first;
    return a.second > b.second;
}
int main() 
{
    int N;
    cin>>N;
    vector<long long> arr(N);
    map<long long, long long>mp;

    for(int i = 0; i< N; i++)
    {
        cin>> arr[i];
        mp[arr[i]]++;

    }
    // for(int i = 0; i< N; i++)
    // {
    //     cout<<arr[i]<<" "<<mp[arr[i]]<<endl;
    // }
    vector<pair<long long, long long>> v;
    for (auto it = mp.begin(); it != mp.end(); ++it)
    {
        v.push_back({ it->first, it->second });
    }
    // map key : value
    sort(v.begin(),v.end(),comp);
    // set<long long > keys;
    // for(int i = 0; i< N; i++)
    // {
    //     v[i].first;
    // }
    for(int i = 0; i< v.size(); i++)
    {
        for(int j=0 ; j< v[i].second; j++)
        {
            cout<<v[i].first<<" ";
        }
    }

    return 0;
}