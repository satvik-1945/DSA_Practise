#include <iostream>
#include <vector>

using namespace std;


void helper(int i, vector<int> &space, int n, vector<int> &temp, int sum,int &flag) {
    // int flag  = 0;
    if (sum > n) {
        return;
    }
    if (i == space.size()) {
        if (sum == n)   
            flag = 1;
        return ;
    }
    if (sum == n) {
        flag = 1;
        return ;
    }
    for (int j = i; j < space.size(); j++) {
        if( flag == 1)
            break;
        sum += space[j];
        temp.push_back(space[j]);
        helper(j, space, n, temp, sum,flag);  
        sum -= space[j];
        temp.pop_back();
    }
}

int main() 
{
    int test;
    cin >> test;
    while (test--) {
        int n, k, x;
        cin >> n >> k >> x;
        vector<int> space;
        // vector<vector<int>> ans;
        for (int i = 1; i <= k; i++) {  
            if (i == x)
                continue;
            space.push_back(i);
            // cout<<space[0]<<space[1]<<endl;
        }
        vector<int> temp;
        int sum = 0;
        int flag = 0;
        helper(0, space, n, temp, sum,flag);
        if (flag != 0) {
            cout << "YES" << endl;
            cout << temp.size() << endl;
            for (int i = 0; i < temp.size(); i++) {
                cout << temp[i] << " ";
            }
            cout << endl;
        }
        else {
            cout<<"NO"<<endl;}
    }
    return 0;
}
