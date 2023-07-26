#include <bits/stdc++.h>
using namespace std;



int main() {
    int n, m;
    cin >> n >> m;
    
    int src, target;
    cin >> src >> target;
    
    vector<int>curse(n);
    for(int i = 0; i < n; i++)
    {
        cin>> curse[i];
    }

    vector<int> adj[n + 1];
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[b].push_back(a);
        adj[a].push_back(b);
    }


    queue<pair<int, int>> q;
    vector<int> vis(n + 1, -1);
    for(int i = 0; i< n ; i++)
    {
        if(curse[i] == 1)
        {
            vis[i] = 1;
        }
    }
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
        cout<< -1;
    } else {
        cout <<  minDist;
    }

    return 0;
}