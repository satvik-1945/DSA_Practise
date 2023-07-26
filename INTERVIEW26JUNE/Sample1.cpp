#include<bits/stdc++.h>
using namespace std;

#define int long long int

int dx[] ={+1,-1,+1,-1,+2,-2,-2,+2};
int dy[] ={+2,-2,-2,+2,+1,-1,+1,-1};
bool check(int x,int y,int n, vector<vector<int>>vis)
{
    return (x>0 and y > 0 and x<=n and y <=n and vis[x][y] == -1);
}
void KnightPos(int n , int srcx,int srcy,int tarx ,int tary)
{
    vector<vector<int>> vis(n+1,vector<int>(n+1, -1));

    queue<pair<pair<int,int>,int>>q;
    q.push({{srcx,srcy},0});
    while(!q.empty())
    {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int steps = q.front().second;

        if( x == tarx and y == tary)
        {
            cout<<steps;
            break;
        }
        for(int i = 0; i < 8; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(check(nx,ny,n,vis))
            {
                vis[nx][ny]  = 1;
                q.push({{nx,ny},steps+1});
            }
        }

    }
    
}
signed main()
{
    
}