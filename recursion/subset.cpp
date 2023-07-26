#include<bits/stdc++.h>
using namespace std;
int recursion(vector<int> v, int i, int &count)
{
    if( i == v.size())
        return count ;
    recursion(v,i+1,count);
    count ++;
    recursion(v,i+1,count);
    // count++;
    return count;
}
int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++)
    {
        cin>>v[i];
    }
    int count = 0;
    int res = recursion(v,0,count);
    cout<<res+1<<endl;
}