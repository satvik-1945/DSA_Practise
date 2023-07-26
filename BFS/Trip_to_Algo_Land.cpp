#include <bits/stdc++.h>
using namespace std;
void findpath(vector<vector<int>> &paths,vector<int> & path,int node,vector<vector<int>> &par)
{
    if (node == 1)
    {
        paths.push_back(path);
    }
    else
    {
        for (int parent : par[node])
                {
                    findpath(paths,path,parent,par);
                }

    }
    path.pop_back();
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> adj[n + 1];
    vector<int> vis(n + 1, -1);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[b].push_back(a);
        adj[a].push_back(b);
    }
    vector<vector<int>> par(n + 1);
    par[1].push_back(-1);

    queue<pair<int, int>> q;
    q.push({1, 0});
    vis[1] = 0;
    int ans = INT_MAX;

    while (!q.empty())
    {
        int node = q.front().first;
        int dis = q.front().second;
        q.pop();

        if (node == n && dis < ans)
        {
            ans = dis;
        }

        for (auto it : adj[node])
        {
            if (vis[it] == -1)
            {
                vis[it] = dis + 1;
                q.push({it, dis + 1});
                par[it].push_back(node);
            }
            else if (vis[it] == dis + 1)
            {
                par[it].push_back(node);
            }
        }
    }

    if (ans == INT_MAX)
    {
        cout << -1 << endl;
    }
    else
    {
        vector<vector<int>> paths;
        vector<int> path;

        function<void(int)> findPaths = [&](int node) {
            path.push_back(node);

            if (node == 1)
            {
                paths.push_back(path);
            }
            else
            {
                for (int parent : par[node])
                {
                    findPaths(parent);
                }
            }

            path.pop_back();
        };

        findpath(paths,path,n,par);

        reverse(paths.begin(), paths.end());

        set<int> uniqueNodes;

        for (auto path : paths)
        {
            for (int i = 0; i < path.size(); i++)
            {
                uniqueNodes.insert(path[i]);
            }
        }

        for (int node : uniqueNodes)
        {
            cout << node << " ";
        }

        cout << endl;
    }

    return 0;
}
