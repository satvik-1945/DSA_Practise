#include <iostream>
#include <vector>

using namespace std;

vector<int> vis;
vector<vector<int>> adj;
bool flag = false;

void DFS(int n) {
    vis[n] = 1;

    for (auto it : adj[n]) {
        if (vis[it] == 0) {
            DFS(it);
        } else if (vis[it] == 1) {
            flag = true;
            return;
        }
    }

    vis[n] = 2;
}

int main() {
    int n, m;
    cin >> n >> m;

    adj.resize(n + 1);
    vis.resize(n + 1, 0);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    for (int i = 1; i <= n; i++) {
        if (vis[i] == 0) {
            DFS(i);
        }
    }

    if (flag) {
        cout << "NO";
    } else {
        cout << "YES";
    }

    return 0;
}
