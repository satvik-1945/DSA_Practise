// You are given a bracket sequence of length N
// �
//  consisting of only '(' and ')'. Your task is to output an array of length N
// �
// . The ith
// �
// �
// ℎ
//  element in the array must be equal to the index of the corresponding bracket in the sequence of the ith
// �
// �
// ℎ
//  bracket. If there is no corresponding bracket then the value in the array at that position should be -1. Please look at the sample testcase for a better understanding.

// 1≤N≤106
// 1
// ≤
// �
// ≤
// 10
// 6
// INPUT
// The first line contains a string of the brackets of length N
// �
// .

// OUTPUT
// Output a space separated array of N
// �
//  integers.

// EXAMPLE
// Sample 1 INPUT:

#include <bits/stdc++.h>
using namespace std;

int main() {

  string str = "";
  cin>> str;
  int  n = str.length();
  stack <int> st;
  vector<int> ans(n);
  for (int i = 0; i < n; i++)
  {
    ans[i] = -1;
        if(str[i] == ')')
        {
            if(!st.empty())
            {
                ans[i] = st.top();
                ans[st.top()] = i;
                st.pop();
            }
        }
        else
            st.push(i);
  }
  for(int i = 0 ; i< n; i++ )
  {
    cout<<ans[i]<<" ";
  }
  return 0;

}   