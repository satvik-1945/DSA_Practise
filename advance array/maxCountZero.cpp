#include<bits/stdc++.h>

int max_zero(vector<int> v,int k)
{
    int n = v.size();
    int count =0;
    int  max_ = 0;

    for(int i = 0; i < k ; i++)
    {
        if(arr[i] == 0)
        count ++;
    }
    for(int i = k; i < n ; i++)
    {
        if(arr[i-k]  == 0)
        count--;
        max_ = max(max_ ,count );
    }
    return max_;
}
using namespace std;
int main()
{

}