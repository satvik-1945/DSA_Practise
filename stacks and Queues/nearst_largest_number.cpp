// // There are N
// // �
// //  people in a line from left to right and you have been given their heights. There is a blackboard to the extreme left. Unfortunately everyone is not able to see the blackboard because there is some person with a greater height to the left of him.

// // For each person i
// // �
// // , output the height of the nearest person to the left with a height greater than hi
// // ℎ
// // �
// //  because it is this person that is blocking the blackboard view. If there is no person blocking the blackboard output -1.

// // 1≤N≤106
// // 1
// // ≤
// // �
// // ≤
// // 10
// // 6

// // 1≤hi≤109
// // 1
// // ≤
// // ℎ
// // �
// // ≤
// // 10
// // 9
// // INPUT
// // The first line contains a single integer N
// // �
// // . The next line contains N
// // �
// //  integers representing the heights of the people from left to right.

// // OUTPUT
// // Output N
// // �
// //  integers.

// // EXAMPLE

// // Sample 1 INPUT:

// #include <bits/stdc++.h>
// using namespace std;
// vector<int> nearset_largest(vector<int> arr)
// {
//     vector<int> ans;
//     stack<int> st;
//     for(int i = 0; i < arr.size(); i++)
//     {
//         while(!st.empty() and st.top()<=arr[i])
//         {
//             st.pop();
//         }
//         if(st.empty())
//         {
//             ans.push_back(-1);
//         }
//         else
//         {
//            ans.push_back(st.top());
//         }
//         st.push(arr[i]);
//     }
//     return ans;
// }
// int main()
// {
//     int n;
//     cin>> n;
//     // string str;
//     vector<int> arr(n);
//     vector<int> ans;
//     for(int i = 0; i < n; i++)
//     {
//         cin>> arr[i];
//     }
//     ans = nearset_largest(arr);
//     for(int i = 0; i < n; i++)
//     {
//         cout<<ans[i]<<" ";
//     }

//   return 0;
// }

#include <bits/stdc++.h>
using namespace std;

vector<int> getGreaterHeights(int n, vector<int> &height)
{
    stack<int>stk;

    vector<int> v(n, -1);

    // v[0] = -1;
    stk.push(height[0]);

    for (int i = 1; i < n; i++)
      {  while (!stk.empty() && stk.top() <= height[i])
            stk.pop();

    if (!stk.empty() && stk.top() > height[i])
    {
        v[i] = stk.top();
    }
    stk.push(height[i]);}
return v;
}

int main()
{
    int inputLength;
    cin>> inputLength;
    vector<int> heightOfPeople(inputLength);
    for (int
             index = 0;
         index < inputLength; index++)
    {
        cin >> heightOfPeople[index];
    }

    vector<int> greaterHeights = getGreaterHeights(inputLength, heightOfPeople);
    for (int height : greaterHeights)
    {
        cout << height << " ";
    }
    return 0;
}