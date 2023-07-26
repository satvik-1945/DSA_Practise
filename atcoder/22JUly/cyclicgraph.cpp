#include<bits/stdc++.h>
using namespace std;
vector<int> ans;
bool dfs(vector<vector<int>>&adj,int n,vector<int>&vis,int x)
{
    if(vis[x] == 1)
        return true;
    vis[x] = 1;
    bool se = false;
    for(auto child : adj[x])
    {
        se = dfs(adj,n,vis,child);
        if(se == true)
            {
                ans.push_back(child);
            }
    }
    vis[x] = 0;
    return se;
}
int main()
{
    int n;
    cin>> n;
    vector<vector<int>>adj(n+1);
    vector<int> vis(n+1, -1);
    vector<int>v(n+1);
    for(int i=1; i<=n; i++)
    {
        cin>> v[i];
    }
    for(int i=1; i<=n; i++)
    {
        adj[i].push_back(v[i]);
        // adj[v[n]].push_back(i));
    }
    for(int i = 1; i<=n; i++)
    {
        if (vis[i] == -1)
        {
            bool sems = dfs(adj,n,vis,i);
            if(sems == true)
                break;
        }
    }   
    reverse(ans.begin(),ans.end()) ;
    cout<<ans.size()<<endl;
    for(int i = 1; i<ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<ans[0];
}
// vis 0 1 
// vis = -1 