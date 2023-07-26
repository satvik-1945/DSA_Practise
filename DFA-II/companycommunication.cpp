    #include <bits/stdc++.h>
    using namespace std;
int N,M;
vector<int> vis;
vector<vector<int>>adj;
void DFS(int n)
{
    vis[n] = 1;
    for(auto child:adj[n])
    {
        if(vis[child] != 1)
            DFS(child);
    }
}
int main()
{
    cin>>N>>M;
    vis.resize(N+M, 0);
    adj.resize(N+M);

    for(int i = 0 ; i< N ; i++)
    {
        int k;
        cin>>k;
        for(int j = 0 ; j< k ; j++)
        {
            int lang;
            cin>>lang;
            lang--;
            adj[i+M].push_back(lang);
            adj[lang].push_back(i+M);
        }
    }
    DFS(M);
    int flag = 0;
    for(int i = M ; i< N+M ; i++)
    {
        if(vis[i]!= 1)
        {
            flag = 1;
            break;
        }

    }
    if(flag==1)
    {
        cout<<"NO";
    }
    else 
    {
        cout<<"YES";
    }
  return 0;

}