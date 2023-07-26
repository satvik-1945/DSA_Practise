#include <bits/stdc++.h>
using namespace std;

void findPaths(vector<int>& path, int node, vector<vector<int>>& par, vector<set<int>>& paths)
{
    if (node == 1)
    {
        path.push_back(node);
        reverse(path.begin(), path.end());
        paths.push_back(set<int>(path.begin(), path.end()));
        path.pop_back();
        return;
    }

    path.push_back(node);
    for (int parent : par[node])
    {
        findPaths(path, parent, par, paths);
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
        vector<int> path;
        vector<set<int>> paths;
        findPaths(path, n, par, paths);

        set<int> uniqueNodes;

        for (auto path : paths)
        {
            for (int node : path)
            {
                uniqueNodes.insert(node);
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