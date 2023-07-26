#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;

void dfs(int v, int p, int dis, int &dis_max, int &a)
{
    if (dis > dis_max)
    {
        dis_max = dis;
        a = v;
    }
    for (auto child : adj[v])
    {
        if (child != p)
        {
            dfs(child, v, dis + 1, dis_max, a);
        }
    }
}

vector<int> bfs(int src)
{
    int n = adj.size();
    vector<int> dist(n, 1e9);
    queue<int> q;

    q.push(src);
    dist[src] = 0;

    while (!q.empty())
    {
        int v = q.front();
        q.pop();

        for (int u : adj[v])
        {
            if (dist[u] == 1e9)
            {
                q.push(u);
                dist[u] = dist[v] + 1;
            }
        }
    }

    return dist;
}

int main()
{
    int n;
    cin >> n;
    adj.resize(n);

    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int dis_max = -1;
    int a;
    int v = 0;
    int p = 0;
    int dis = 0;
    dfs(v, -1, dis, dis_max, a);

    dis_max = 0;
    int b;
    dfs(a, -1, 0, dis_max, b);

    auto dist_a = bfs(a);
    auto dist_b = bfs(b);

    for (int i = 0; i < n; ++i)
    {
        cout << max(dist_a[i], dist_b[i]) << " ";
    }
    cout << endl;

    return 0;
}
