#include <bits/stdc++.h>
using namespace std;

int toh_steps(int n)
{
    if(n == 0)
        return 0;
    return 2*toh_steps(n-1) +1;
}
void toh(int n , int from , int to , int aux , vector<vector<int> >&v)
{
    if(n == 0) {return;}
    toh(n-1,from, aux, to,v);
    vector<int>l;
    l.push_back(n);
    l.push_back(from);
    l.push_back(to);
    v.push_back(l);
    toh(n-1,aux,to,from,v);   

}
int main() {
    int n ;
    cin >> n;
    int s = toh_steps(n);
    cout<<s<<endl;
    vector<vector<int>> v;
    toh(n,1,2,3,v);
    for(int i=0;i<v.size();i++)
    {
        for(int j=0; j< v[i].size(); j++)
        {
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }

  

  return 0;

}