#include <bits/stdc++.h>
using namespace std;
void dfs(int node,vector<vector<int>> &adj,vector<bool> &visited,vector<int> &leafNodes)
{
    visited[node] = true;
    if(adj[node].size() == 1 && node != 0)
    {
        leafNodes[node] = 1;
        return;
    }
    for(auto child:adj[node])
    {
        if(!visited[child])
        {
            dfs(child,adj,visited,leafNodes);
            leafNodes[node] += leafNodes[child];
        }
    }
}

int main()
{
    int n;cin>>n;
    vector<vector<int>> adj(n);
    vector<int> leafNodes(n);
    for(int i=0;i<n-1;i++)
    {
        int u,v;cin>>u>>v;
        u--,v--;
        =
    }
    vector<bool> visited(n,false);
    dfs(0,adj,visited,leafNodes);
    // for(int i=0;i<n;i++)cout<<leafNodes[i]<<" ";
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
    return 0;
}