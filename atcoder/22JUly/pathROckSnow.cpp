#include <bits/stdc++.h>
using namespace std;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

bool check(int nx, int ny, int n, int m, vector<vector<int>> &vis, vector<vector<string>> &graph)
{
    if (nx >= 0 && nx < n && ny >= 0 && ny < m && vis[nx][ny] != 1 && graph[nx][ny] != "#")
        return true;
    return false;
}

int dfs(int x, int y, int dis, vector<vector<int>> &vis, vector<vector<string>> &graph)
{
    vis[x][y] = 1;
    int ans = dis;

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (check(nx, ny, vis.size(), vis[0].size(), vis, graph))
        {
            ans = max(ans, dfs(nx, ny, dis + 1, vis, graph));
        }
    }
    // vis[x][y] = -1;

    return ans;
}



int helper(int x,int y,vector<vector<string>>& graph,int n,int m,int dir){
    graph[x][y] = "#" ;

    if(dir==-1)
    {
        if(check(x-1,y,n,m,graph))
        return 1+helper(x-1,y,n,m,graph);
        else{
            return max({helper(x,y,graph,n,m,1),helper(x,y,graph,n,m,-2),helper(x,y,graph,n,m,2)});
        }
    }
    if(dir == 1)
    {
        if(check(x+1,y,n,m,graph))
            return 1+helper(x+1,y,n,m,graph);
        else
        {
            return max({helper(x,y,graph,n,m,-1),helper(x,y,graph,n,m,-2),helper(x,y,graph,n,m,2)});
 
        }
    }
    if(dir == -2)
    {
         if(check(x,y-1,n,m,graph))
            return 1+helper(x,y-1,n,m,graph);
        else
        {
            return max({helper(x,y,graph,n,m,1),helper(x,y,graph,n,m,-1),helper(x,y,graph,n,m,2)});
 
        }
    }
    if(dir == 2)
    {
        if(check(x,y+1,n,m,graph)
        {
            return 1+helper(x,y-1,n,m,graph);
        }
        else
            
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    string str;
    vector<vector<string>> graph(n, vector<string>(m));
    
    vector<vector<int>> vis(n, vector<int>(m, -1));
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++)
        {
            graph[i][j] = s[j];
            if (i == 0 || j == 0 || i == n - 1 || j == m - 1)
            {
                vis[i][j] = 1;
            }
            if (s[j] == '#')
            {
                vis[i][j] = 1;
            }
        }
    }
    int ans=INT_MIN;
    graph[1][1]="#";
    ans=helper(1,1,graph,vis,n,m);
    cout << ans << endl;
    return 0;
}
