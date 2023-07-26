#include <bits/stdc++.h>
using namespace std;
#define int long long

int DFS(vector<vector<int>> & adj ,int src ,vector<int> & ans,vector<int> &vis)
{
    vis[src] = 1;
     if (adj[src].size() == 1 and src != 1) 
    {        
        ans[src] = 1;
        return ans[src];
    }
    for(auto it: adj[src])
    {
        // flag = 1;
        if(vis[it] == -1)
            ans[src]+= DFS(adj,it,ans,vis);
        
    }
    return ans[src];
   
}

signed main()
{
    int test;
    cin>> test;
    while(test--)
    {
        int n; 
        cin>> n;
        vector<vector<int>> adj(n+1);
        vector<int> outdegree(n+1,0);
        for(int i = 1 ;i < n ; i++)
        {
            int u , v;
            cin>>u>>v;
            // int min_ = min(u,v);
            // int max_ = max(u,v);
            // // outdegree[u]++;
            // adj[min_].push_back(max_);
            // // adj[v].push_back(u);
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int q;
        cin>> q;
        vector<int> ans(n+1);
        vector<int> vis(n+1,-1);
        int count = DFS(adj,1,ans,vis);
        while (q--)
        {
            int x , y;
            cin>> x>>y;
            
            cout<<ans[x]*ans[y]<<endl;      
        }
    }
}   