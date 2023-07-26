#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
void DFS(vector<int> &vis , int src , int n,int dis)
{
    if(src  == n)
    {
        return ;
    }
    for(auto child : adj[src])
    {
        vis[child] = max(dis+1,vis[child]);
        // vis[child] =vdis+1;
        DFS(vis, child, n,dis+1);
    }
}

int main() 
{
    int n , m;
    cin>> n >> m;
    adj.resize(n+1);
    for(int i = 0; i < m; i++)
    {
        int u , v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    vector<int> vis(n+1 ,0);
    int src = 1;
    DFS(vis,src, n, 0);
    if(vis[n] == 0)
    {
        cout<<-1;
    }
    else
    {
        cout<<vis[n]+1<<endl;
    }
    return 0;

}