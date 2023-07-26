#include <bits/stdc++.h>
using namespace std;

#define intt long long int;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

bool check1(vector<vector<int>> & vis , int  nx , int ny, int n , int m )
{
    return (nx >= 0 && ny >= 0 && nx < n && ny < m && vis[nx][ny] != 1);
}

int main() 
{
    int n, m;
    cin>> n>> m;
    vector<vector<string>>graph(n , vector<string >(m));
    vector<vector<int>> visvirus(n, vector<int>(m,-1));
    vector<vector<int>> vis(n, vector<int>(m, -1));
    queue<pair<pair<int,int>,int>> q;
    vector<vector<int>> ans(n,vector<int>(m,INT_MAX));
    int srcx;
    int srcy;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;

        for (int j = 0; j < m; j++)
        {
            graph[i][j] = s[j];  
            if(graph[i][j] == "#")
            {
                vis[i][j] = 1;
                visvirus[i][j] = 1;
            }
            if(graph[i][j] == "d")
            {
                q.push({{i,j},0});
                visvirus[i][j] = 1;
            }
            if(graph[i][j] == "s")
            {
                 srcx = i;
                 srcy = j;
                vis[i][j] = 1;
            }    
            
        }
    }

    while (!q.empty())
    {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int dis = q.front().second;
        q.pop();

        ans[x][y] = dis;
        for(int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(check1(visvirus, nx , ny , n , m))
            {
                visvirus[nx][ny] = 1;
                q.push({{nx,ny},dis+1});
            }
        }

    }
    q.push({{srcx,srcy},0});
    int flag = 0;
    while(!q.empty())
    {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int dis = q.front().second;
        q.pop();    

        if(graph[x][y] =="h")
        {
            flag = 1;
            break;
        }
        for(int i = 0 ; i< 4 ; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(check1(vis,nx,ny, n, m) and dis+1 < ans[nx][ny] )
            {
                vis[nx][ny] = 1;
                q.push({{nx,ny},dis+1});
            }
        }
    }
    if(flag == 1)
        cout<<"YES";
    else
        cout<<"NO";

    return 0;
}
    



