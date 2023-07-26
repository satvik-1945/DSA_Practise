#include <algorithm>
#include <array>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
enum
{
  L,
  R
};
void add_edge(vector<vector<long long>> &adj, long long u, long long v)
{
  adj[u].push_back(v);
  adj[v].push_back(u);
}
long long d2(long long x1, long long y1, long long x2, long long y2)
{
  return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}
vector<bool> bfs(long long source, vector<vector<long long>> &adj)
{
  long long n = adj.size();
  vector<bool> vis(n);
  queue<long long> q;
  q.push(source);
  vis[source] = true;
  while (!q.empty())
  {
    long long v = q.front();
    q.pop();
    for (long long u : adj[v])
    {
      if (!vis[u])
      {

        vis[u] = true;
        q.push(u);
      }
    }
  }
  return vis;
}
void solve()
{
  long long  m, n;
  cin >>  m >> n;
  vector<array<long long, 3>> circles(n);
  for (long long i = 0; i < n; ++i)
  {
    for (long long j = 0; j < 3; ++j)
    {
      cin >> circles[i][j];
    }
  }
  vector<vector<long long>> adj(n + 4);
  // edges with boundary
  for (long long i = 0; i < n; ++i)
  {
    long long idx = i + 2;
    if (circles[i][0] - circles[i][2] <= 0)
      add_edge(adj, L, idx);
    if (circles[i][0] + circles[i][2] >= m)
      add_edge(adj, R, idx);
    // if (circles[i][1] - circles[i][2] <= 0)
    //   add_edge(adj, B, idx);
    // if (circles[i][1] + circles[i][2] >= m)
    //   add_edge(adj, T, idx);
  }
  // chains
  for (long long i = 0; i < n; ++i)
  {
    long long idxi = i + 2;
    for (long long j = i + 1; j < n; ++j)
    {
      long long idxj = j + 2;
      if (d2(circles[i][0], circles[i][1], circles[j][0],
             circles[j][1]) <= (circles[i][2] + circles[j][2]) *
                                   (circles[i][2] + circles[j][2]))
        add_edge(adj, idxi, idxj);
    }
  }
//   vector<bool> TV = bfs(T, adj);
//   vector<bool> BV = bfs(B, adj);
  vector<bool> LV = bfs(L, adj);
//   vector<bool> RV = bfs(R, adj);
  bool ans =  (LV[R]);
  cout << (ans ? "YES" : "NO") << endl;
}
int main()
{
  long long t;
  cin >> t;
  while (t--)
  {
    solve();
  }
  return 0;
}