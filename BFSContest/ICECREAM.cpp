#include <bits/stdc++.h>
using namespace std;

#define int long long 

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
bool check(vector<vector<int>>& vis,int n , int m , int nx , int ny)
{
    if(nx >= 0 && ny >= 0 && nx < n && ny < m && vis[nx][ny] != 1)
    {
        return true;
    }
    return false;
}
signed main()
{
    int flag = 0;
    int n, m , k;
    cin >> n >> m >> k;

    vector<vector<string>> graph(n, vector<string>(m));
    vector<vector<int>> vis(n, vector<int>(m, -1));
    queue<pair<pair<int,int>,int>> q;

    for(int i = 0 ; i< n ; i++)
    {
        string s;
        cin >> s;
         for (int j = 0; j < m; j++)
        {
            graph[i][j] = s[j];

            if(graph[i][j] == "i")
            {
                q.push({{i,j},0});
                vis[i][j] = 1;
            }
            if(graph[i][j] == "#")
            {
                vis[i][j] = 1;
            }
            if(graph[i][j] == "h")
            {
                vis[i][j] = 2 ;
            }
            
        }
    }
    int ans = -1;
    while(!q.empty())
    {
        int x = q.front().first .first;
        int y = q.front().first.second;
        int dis = q.front().second;
        q.pop();

        
        if(graph[x][y] == "h")
        {
            ans = dis;
            break;
        }

        for(int i = 0; i < 4 ; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(check(vis,n,m,nx,ny))
            {
                vis[nx][ny] = 1;
                q.push({{nx,ny},dis +1});
            }
        }
    }
    if(ans != -1 && ans <= k)
    {
       
//    cout<<ans<<endl;
         cout<<"YES";
    }
    else{
        cout<<"NO";
    }
        

  return 0;

}