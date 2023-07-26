#include <bits/stdc++.h>
using namespace std;
int  dfs(vector<int>& ans, int n, vector<vector<int>>& adj,vector<int> &prof) 
{    
    for (auto child : adj[n]) 
    {        
        ans[n]+= dfs(ans, child, adj,prof);
    }
    ans[n] += prof[n];
    return ans[n];
}
int main() 
{
    int n;
    cin >> n;
    vector<int> v(n + 1);
    v[0] = -1;
    v[1] = -1;
    vector<vector<int>> adj(n + 1);
    vector<int> ans(n + 1);
    for (int i = 2; i < n + 1; i++) {
        cin >> v[i];
        adj[v[i]].push_back(i);
    }
    vector<int> prof(n+1);
    for(int i =1 ; i< n + 1; i++)
    {
        cin>>prof[i];
    }
    int max_ = dfs(ans, 1 , adj, prof);
    for(int i = 1; i< n + 1; i++)
    {
        max_ = max(max_,ans[i]);
    }
    cout<<max_<<endl;
    return 0 ;
}
