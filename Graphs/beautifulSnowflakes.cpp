#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    pair<int, int> input;
    vector<pair<int, int>> proc;
    for (int i = 0; i < n; i++)
    {
        cin >> input.first >> input.second;
        proc.push_back(input);
        // cout<<input.first<<input.second<<endl;
    }
    vector<int> adj[n + 1];
    for (int i = 1; i < n + 1; i++)
    {
        if (proc[i - 1].first != proc[i - 2].first)
        {
            adj[proc[i - 1].first].push_back(proc[i - 1].second);
            adj[proc[i - 1].second].push_back(proc[i - 1].first);
        }
    }
    // vector<int,int>
    vector<int> degree(n + 1);
    for (int i = 1; i < n + 1; i++)
    {
        degree[i] = adj[i].size();
        // cout<<i<<" "<<degree[i]<<endl;
    }
    int snowflakes = 0;
    // for (int i = 1; i < n + 1; i++)
    // {
    //     cout << i << ": ";
    //     for (int j = 0; j < adj[i].size(); j++)
    //     {
    //         cout << adj[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    vector<int> mp(n+2,0);
    for (int i = 1; i < n + 1; i++)
    {
        if (degree[i] == 0)
        {
            mp[0]++;
            
        }
        if (degree[i] > 1)
        {
            int flag = 0;
            for (auto it : adj[i])
            {
                if (degree[it] != 1)
                {
                    flag = 1;
                    break;
                }
            }
            if (flag == 0)
            {
                mp[degree[i]]++;
                // cout << "hey" << snowflakes << endl;
            }
        }
    }
    // cout << degree[11] << endl;
    for(int i = 0 ; i< n+2 ; i++)
    {
        if(mp[i] == 1)
            snowflakes++;
    }

    cout << snowflakes << endl;

    return 0;
}