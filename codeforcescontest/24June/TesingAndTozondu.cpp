#include<bits/stdc++.h>
using namespace std;

#define int long long int

signed main()
{
    int test;
    cin>> test;
    while (test--)
    {
        int n , m;
        cin>> n>> m;
        vector<int> tsondu(n);
        vector<int>tenzing(m);
        int sumx = 0;
        int sumy = 0;
        for(int i = 0 ; i< n ; ++i)
        {
            cin>>tsondu[i];
            sumx += tsondu[i];
        }
        for(int i = 0 ; i< m ; ++i)
        {
            cin>>tenzing[i];
            sumy += tenzing[i];
        }
        if(sumx == sumy)
        {
            cout<<"Draw"<<endl;
        }
        else if(sumx>sumy)  
        {
            cout<<"Tsondu"<<endl;
        }
        else 
        {
            cout<<"Tenzing"<<endl;
        }

    }
}