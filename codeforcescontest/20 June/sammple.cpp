#include <bits/stdc++.h>
using namespace std;

int dfs(int node, vector<vector<int>>& adj_list, vector<bool>& visited,vector<int>& leafNodes) 
{
    visited[node] = true;
    bool is_leaf=true;
    int total = 0;
    for (int child : adj_list[node]) {
        if (!visited[child]) {
           is_leaf=false;
           total+= dfs(child, adj_list, visited,leafNodes);
        }
    }
    if(is_leaf){
        leafNodes[node] = 1;
        return 1;
    }
    else
        leafNodes[node] = total;
    return total;
}

void solve()
{
    int n;cin>>n;
    vector<vector<int>> adj(n);
    vector<int> leafNodes(n);
    for(int i=0;i<n-1;i++)
    {
        int u,v;cin>>u>>v;
        u--,v--;
        if(u<v)
            adj[u].push_back(v);
        else
            adj[v].push_back(u);
    }
    vector<bool> visited(n,false);
    dfs(0,adj,visited,leafNodes);
    for(int i=0;i<n;i++)cout<<leafNodes[i]<<" ";
    int q;cin>>q;
    while(q--)
    {
        int x,y;cin>>x>>y;
        x--,y--;
        int ansx = leafNodes[x];
        if(ansx == 0)ansx =1;
        int ansy = leafNodes[y];
        if(ansy == 0)ansy =1;
        cout<<ansx*ansy<<"\n";
    }
}