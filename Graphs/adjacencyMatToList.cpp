#include <bits/stdc++.h>
using namespace std;

int main()
{

    // cout << "Hello World";
    int n;
    cin >> n;
    vector<vector<int>> mat(n, vector<int>(n));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> mat[i][j];
        }
    }
    // mat to list
    vector<int> adj[n];
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (mat[i][j] == 1)
            {   
                if (i == j)
                {
                    adj[i].push_back(j + 1);
                }
                else
                {
                    adj[i].push_back(j + 1);
                    adj[j].push_back(i + 1);
                }
            }
        }
    }
        for (int i = 0; i < n; i++)
        {
            cout << i + 1 << ": ";
            for (int j = 0; j < adj[i].size(); j++)
            {
                cout << adj[i][j] << " ";
            }
            cout << endl;
        }

    return 0;
}