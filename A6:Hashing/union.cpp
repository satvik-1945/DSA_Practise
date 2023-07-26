#include <bits/stdc++.h>
using namespace std;

int main() {

    int N,M;
    cin>> N >>  M ;
    vector<long long > vec1(N);
    vector<long long > vec2(M);
    set<long long> set;
    for(int i = 0 ; i < N ; i++)
    {
        cin>> vec1[i];
        set.insert(vec1[i]);
    }
    for(int i = 0 ; i < M ; i++)
    {
        cin>> vec2[i];
        set.insert(vec2[i]);
    }
    for(auto i : set)
    {
        cout<<i<<" ";
    }


    return 0;

}