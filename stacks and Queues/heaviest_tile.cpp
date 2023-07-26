
// Phil is playing with tiles that each have a certain weight. At the center of the room, he builds a stack of tiles sometimes placing tiles on top and sometimes removing the topmost tile and sometimes he asks people the weight of the heaviest tile in the stack.

// You have been observing Phil and would like to answer all his questions.

// Input
// The first line contains one integer Q
// �
// , representing the number of actions Phil makes.

// Q
// �
//  lines follow, each detailing the action Phil made.

// Each line is of three types:

// 0
// 0
//  represents that Phil removes the topmost tile from the stack.
// 1
// 1
//  w
// �
//  represents that Phil placed a tile of weight w
// �
//  on top of the stack.
// 2
// 2
//  represents that Phil asks someone the weight of the heaviest tile in the stack.
// Constraints
// 1≤Q≤106
// 1
// ≤
// �
// ≤
// 10
// 6
// The weight of each tile is at least 1
// 1
//  and at most 106
// 10
// 6
// .

// Output
// For each time Phil asks someone the weight of the heaviest tile, output the weight of the heaviest tile in the stack in a new line.


#include <bits/stdc++.h>
using namespace std;

int main() {
    int n ;
    cin >> n;
    stack<int> st;
    stack<int>max_element;
    int max_ = INT_MIN;
    while (n--)
    {
        int q;
        cin >> q;
        if(q == 1)
        {
            int w;
            cin >> w;
            st.push(w);
            if(w >max_) max_ = w;
            max_element.push(max_);
        }
        else if(q == 2)
        {
            cout<<max_element.top()<<endl;
        }
        else if(q == 0)
        {
            st.pop();
            if(st.size()!=0)
            max_element.pop();
        }
        
    }


  return 0;

}