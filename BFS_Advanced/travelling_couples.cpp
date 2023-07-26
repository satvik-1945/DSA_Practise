#include <bits/stdc++.h>
using namespace std;

const int MAX_NODES = 1000000;

vector<int> adj[MAX_NODES];
vector<int> visM(MAX_NODES, -1);
vector<int> visF(MAX_NODES, -1);
vector<int> visC(MAX_NODES, -1);
vector<int> ansM(MAX_NODES);
vector<int> ansF(MAX_NODES);
vector<int> ansC(MAX_NODES);
queue<pair<int, int>> q;

void BFS(vector<int>& vis, vector<int>& ans, int c)
{
    while (!q.empty())
    {
        int node = q.front().first;
        int dis = q.front().second;
        int cost = c * dis;
        q.pop();
        ans[node] = cost;
        for (auto it : adj[node])
        {
            if (vis[it] != 1)
            {
                vis[it] = 1;
                q.push({it, dis + 1});
            }
        }
    }
}

int main()
{
    int c1, c2, c3, n, m;
    cin >> c1 >> c2 >> c3 >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    q.push({1, 0});
    visM[1] = 1;
    BFS(visM, ansM, c1);

    q.push({2, 0});
    visF[2] = 1;
    BFS(visF, ansF, c2);

    q.push({n, 0});
    visC[n] = 1;
    BFS(visC, ansC, c3);

    int minCost = INT_MAX;

    for (int i = 1; i <= n; i++)
    {
        int sum = ansC[i] + ansF[i] + ansM[i];
        minCost = min(minCost, sum);
            // cout<<sum<<endl;
            // cout<<ansC[i]<<endl;
            // cout<<ansM[i]<<endl;
            // cout<<ansF[i]<<endl;
    }

    cout << minCost << endl;

    return 0;
}
