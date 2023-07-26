#include <bits/stdc++.h>
using namespace std;
void helper(string& s , int index, vector<string> &v)
{
  if(index == s.length())
  { 
    v.push_back(s);
    return ;
  }
  for(int i = index ; i< s.length(); i++)
  {
    swap(s[index], s[i]);
    helper(s , index +1,v);
    swap(s[index], s[i]);
  }  
}
int main() {

  string s;
  cin>> s;
  vector<string> v;
  helper(s,0, v);
  sort(v.begin(),v.end());
  for(int i = 0; i < v.size(); i++)
  {
    cout<<v[i]<<endl;
  }

  return 0;

}