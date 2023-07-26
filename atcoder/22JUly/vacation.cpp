#include<bits/stdc++.h>
using namespace std;

int main()
{

    int n,d;
    cin>> n>> d;
    vector<string> holidays(n);
    for(int i=0; i<n; i++)
    {
        cin>> holidays[i];
    }
    int max_till_now= 0;
    int max_end_here = 0;
    vector<int>free(d,0);
    for(int i =0; i< n ; i++)
    {
        for(int j=0; j<d; j++)
        {
            if(holidays[i][j] == 'o')
            {
                free[j]++;
            }
        }
    }
    for(int i=0; i<d; i++)
    {
        if(free[i]==n)
        {
            // cout<<free[i]<<endl;
            max_end_here ++;
        }
        if(free[i]<n)
        {
            max_till_now= max(max_till_now,max_end_here);
            max_end_here = 0;
        }
    }
    max_till_now= max(max_till_now,max_end_here);
    cout<<max_till_now<<endl;
    return 0;

}