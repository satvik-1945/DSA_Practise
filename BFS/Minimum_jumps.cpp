#include <bits/stdc++.h>
using namespace std;



int main() {
    int n, m;
    cin >> n >> m;

    vector<int> adj[n + 1];
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[b].push_back(a);
        adj[a].push_back(b);
    }

    int src, target;
    cin >> src >> target;

    queue<pair<int, int>> q;
    vector<int> vis(n + 1, -1);

    q.push({ src, 0 });
    vis[src] = 1;

    int minDist = n + 2;

    while (!q.empty()) {
        int node = q.front().first;
        int dis = q.front().second;
        q.pop();

        if (node == target) {
            minDist = min(minDist, dis);
            break; // Stop the BFS if target is found
        }

        for (auto it : adj[node]) {
            if (vis[it] == -1) {
                vis[it] = 1;
                q.push({ it, dis + 1 });
            }
        }
    }

    if (minDist == n + 2) {
        cout<< 0;
    } else {
        cout <<  minDist;
    }

    return 0;
}