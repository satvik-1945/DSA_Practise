#include <bits/stdc++.h>
#include <array>
using namespace std;
signed main()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> adj1(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj1[u].push_back(v);
        adj1[v].push_back(u);
    }
    set<array<int, 3>> forbidden;
    for (int i = 0; i < k; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        x--;
        y--;
        z--;
        array<int, 3> tmp = {x, y, z};
        forbidden.insert(tmp);
    }
    set<pair<int, int>> visited;
    vector<vector<pair<int, int>>> par(n, vector<pair<int, int>>(n, make_pair(-1, -1)));
    queue<pair<int, int>> q;
    q.push(make_pair(0, 0));
    visited.insert(make_pair(0, 0));
    bool reached = false;
    while (q.size())
    {
        auto p = q.front();
        q.pop();
        int vf = p.first;
        int vs = p.second;
        for (int u : adj1[vs])
        {
            if (forbidden.find({vf, vs, u}) != forbidden.end())
                continue;
            if (visited.find({vs, u}) != visited.end())
                continue;
            par[vs][u] = p;
            q.push({vs, u});
            visited.insert({vs, u});
            if (u == n - 1)
                reached = true;
            if (reached)
                break;
        }
        if (reached)
            break;
    }

    if (!reached)
        cout << "-1\n";
    else
    {
        for (int i = 0; i < n; i++)
        {
            if (par[i][n - 1] != pair<int, int>(-1, -1))
            {
                vector<int> path;
                pair<int, int> cur = {i, n - 1};
                while (cur != pair<int, int>(-1, -1))
                {
                    int vf = cur.first;
                    int vs = cur.second;
                    int pf = par[vf][vs].first;
                    int ps = par[vf][vs].second;
                    path.push_back(vs);
                    cur = {pf, ps};
                }
                reverse(path.begin(), path.end());
                cout << path.size() - 1 << "\n";
                for (int p : path)
                {
                    cout << p + 1 << " ";
                }
                cout << "\n";
                return 0;
            }
        }
    }
    return 0;
}