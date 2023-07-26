    #include <bits/stdc++.h>
using namespace std;

vector<int> adj[4000];
vector<int> visM(4000,-1);
vector<int> visF(4000,-1);
vector<int> visC(4000,-1);
queue<pair<int,int>> q;
void BFS(vector<int> &vis,vector<int> &ans,int c)
{
    while(!q.empty())
    {
        int node = q.front().first;
        int dis = q.front().second;
        int cost = c * dis;
        q.pop();
        ans[node] = cost;
        for(auto it : adj[node])
        {
            if(vis[node] != 1)
            {
                vis[node] = 1;
                q.push({it,dis + 1});
            }

        }

    }

}
int main() {

int c1,c2,c3,n,m;
cin >> c1 >> c2 >> c3 >>n >>m;
for(int i = 0; i < m; i++)
{
    int u,v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
}
//now you have the adjacency matrix;
vector<int> ansM(n);
vector<int> ansF(n);
vector<int> ansC(n);
q.push({1,0});
BFS(visM , ansM , c1);



  return 0;

}