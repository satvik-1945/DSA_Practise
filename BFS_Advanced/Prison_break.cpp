    #include <bits/stdc++.h>
    using namespace std;

    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {1, -1, 0, 0};

bool check(int nx, int ny, int x, int y, vector<vector<int>> &visMonster, vector<vector<string>> &graph)
{
    if (nx >= 0 && ny >= 0 && nx < x && ny < y && visMonster[nx][ny] != 1)
        return true;
    return false;
}

bool check2(int nx, int ny, int x, int y, vector<vector<int>> &ans, int dis, vector<vector<int>> &visA)
{
    if (nx >= 0 && ny >= 0 && nx < x && ny < y && dis < ans[nx][ny] && visA[nx][ny] != 1)
        return true;
    return false;
}

int main()
{
    int flag = 0;
    int n, m;
    cin >> n >> m;

    vector<vector<string>> graph(n, vector<string>(m));
    vector<vector<int>> visMonster(n, vector<int>(m, -1));
    vector<vector<int>> visA(n, vector<int>(m, -1));

    int srcx = -1, srcy = -1;
    queue<pair<pair<int, int>, int>> q;

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;

        for (int j = 0; j < m; j++)
        {
            graph[i][j] = s[j];

            if (s[j] == '#')
            {
                visMonster[i][j] = 1;
                visA[i][j] = 1;
            }
            else if (s[j] == 'M')
            {
                q.push({{i, j}, 0});
                visMonster[i][j] = 1;
            }
            else if (s[j] == 'A')
            {
                srcx = i;
                srcy = j;
                if (srcx == 0 || srcx == n - 1 || srcy == m - 1 || srcy == 0)
                {
                    // cout << dis << endl;
                    cout << "YES" << endl;
                    flag = 1;
                    break;
                }
            }
        }
    }
    if (flag == 1)
        return 0;

    vector<vector<int>> ans(n, vector<int>(m, 1000000));

    while (!q.empty())
    {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int dis = q.front().second;
        q.pop();

        ans[x][y] = dis;

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (check(nx, ny, n, m, visMonster, graph))
            {
                visMonster[nx][ny] = 1;
                q.push({{nx, ny}, dis + 1});
            }
        }
    }


    q.push({{srcx, srcy}, 0});
    visA[srcx][srcy] = 1;

    while (!q.empty())
    {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int dis = q.front().second;
        q.pop();

        if (x == 0 || x == n - 1 || y == m - 1 || y == 0)
        {
            cout << "YES" << endl;
            flag = 1;
            break;
        }

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (check2(nx, ny, n, m, ans, dis + 1, visA))
            {
                visA[nx][ny] = 1;
                q.push({{nx, ny}, dis + 1});
            }
        }
    }
    // for(int i= 0 ; i< n ; i++)
    // {
    //     for(int j = 0 ; j < m ; j++)
    //     cout<<ans[i][j]<<" ";
    //     //    cout<< visMonster[i][j]<<" ";
    //     cout<<endl;
    // }
    if (flag != 1 or srcx == -1 or srcy == -1)
        cout << "NO" << endl;

    return 0;
}
