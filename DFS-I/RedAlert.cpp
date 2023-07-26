#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> colors;
int capacity;
int leafCount;

void dfs(int node, int parent, int countRed) {
    if (colors[node] == 1) {
        countRed++;
    } else {
        countRed = 0;
    }

    if (countRed > capacity) {
        return;
    }

    if (adj[node].size() == 0 ) {
        leafCount++;
        return;
    }

    for (int child : adj[node]) {
        if (child != parent) {
            dfs(child, node, countRed);
        }
    }
}

int main() {
    int N;
    cin >> N >> capacity;

    colors.resize(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> colors[i];
    }

    adj.resize(N + 1);
    for (int i = 1; i < N; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        
    }

    leafCount = 0;
    dfs(1, -1, 0);

    cout << leafCount << endl;

    return 0;
}
