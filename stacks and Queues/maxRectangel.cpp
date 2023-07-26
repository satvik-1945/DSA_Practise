#include <bits/stdc++.h>
using namespace std;
vector<int> nearest_left(vector<int> &arr)
{stack<int> st;
vector<int> ans;
for(int i = 0; i < arr.size();i++)
{
    while (!st.empty() and arr[st.top()] >=arr[i])
    {
        st.pop();
    }
    if(st.empty())
    {
        ans.push_back(-1) ;      
    }
    else
    {
        ans.push_back(st.top());
    }
    st.push(i);
}
return ans;

}
vector<int> nearest_right(vector<int> &arr)
{
stack<int> st;
vector<int> ans(arr.size());
for(int i = arr.size()-1; i >=0;i--)
{
    while (!st.empty() and arr[st.top()] >=arr[i])
    {
        st.pop();
    }
    if(st.empty())
    {
        ans[i] = (arr.size()) ;      
    }
    else
    {
        ans[i]= (st.top());
    }
    st.push(i);
}
return ans;

}
int main() {

  int n ;
  cin >> n;
  vector<int>arr(n);

  for(int i = 0 ; i< n ; i++) 
  {
    cin>> arr[i];
  }
  vector<int> left  = nearest_left(arr);
//   cout<<left[n-1]<<endl;
  vector<int> right = nearest_right(arr);
//   cout<<right[0]<<endl;
  int max_ = INT_MIN;
  vector<int> res;
  
  for(int i= 0 ; i< n ; i++)
{
    int l, r;
    l = (i - left[i]);
    r = right[i] - i;
    int sum = (l + r -1)* arr[i];
    res.push_back((sum));
    // cout<<res[i]<<endl;
    max_ = max(max_, sum);
    
}
cout<<max_<<endl;
  return 0;

}