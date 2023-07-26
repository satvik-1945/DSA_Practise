#include <iostream>
#include <vector>

#define int long long int
using namespace std;

void helper(vector<vector<int>>& ans, const vector<int>& s, int i, vector<int>& temp) {
    if (i == s.size()) {
        ans.push_back(temp);
        // bitwiseAnd
        return;
    }
    temp.push_back(s[i]);
    helper(ans, s, i + 1, temp);
    temp.pop_back();
    helper(ans, s, i + 1, temp);
}

int bitwiseAnd(const vector<int>& arr) {
    if (arr.empty()) {
        return 0; // Handle empty array
    }

    int result = arr[0];
    for (int i = 1; i < arr.size(); i++) {
        result &= arr[i];
    }

    return result;
}

signed main() {
    int test;
    cin >> test;
    while (test--) {
        int n, b;
        cin >> n >> b;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        vector<vector<int>> ans;
        vector<int> temp;
        helper(ans, arr, 0, temp);
        int flag = 0;
        for (int i = 0; i < ans.size(); i++) {
            int seme = bitwiseAnd(ans[i]);
            if (seme == b) {
                cout << "YES";
                flag = 1;
                break;
            }
        }
        if (flag == 0) {
            cout << "NO";
        }
        cout << endl;
    }
    return 0;
}
    