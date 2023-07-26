#include <bits/stdc++.h>
using namespace std;

int dfs(vector<int>& vis, vector<int>& ans, int n, vector<vector<int>>& adj) {
    vis[n] = 1;
    int dis = 0;
    for (auto child : adj[n]) {
        // if (vis[child] == -1) {
            // vis[child] = 1;
            dis += dfs(vis, ans, child, adj);
        // }
    }
    ans[n] = dis;
    return dis + 1;
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n + 1);
    v[0] = -1;
    v[1] = -1;
    vector<vector<int>> adj(n + 1);

    for (int i = 2; i < n + 1; i++) {
        cin >> v[i];
        adj[v[i]].push_back(i);
    }

    vector<int> vis(n + 1, -1);
    vector<int> ans(n + 1);
    int s = dfs(vis, ans, 1, adj);

    for (int i = 1; i < n + 1; i++) {
        cout << ans[i] << " ";
    }

    return 0;
}
