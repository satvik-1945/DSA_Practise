    //{ Driver Code Starts
    // Initial template for C++

    #include <bits/stdc++.h>
    using namespace std;


    // } Driver Code Ends
    // User function template for C++

    class Solution{
        public:
        void helper(vector<vector<int>> &m, int n, string &temp, vector<string> &ans, int i, int j)
    {
        if (i == n - 1 && j == n - 1)
        {
            ans.push_back(temp);
            return;
        }

        m[i][j] = 0; // Mark the current cell as visited

        if (i - 1 >= 0 && m[i - 1][j] == 1)
        {
            temp += "U";
            helper(m, n, temp, ans, i - 1, j);
            temp.pop_back();
        }

        if (i + 1 < n && m[i + 1][j] == 1)
        {
            temp += "D";
            helper(m, n, temp, ans, i + 1, j);
            temp.pop_back();
        }

        if (j + 1 < n && m[i][j + 1] == 1)
        {
            temp += "R";
            helper(m, n, temp, ans, i, j + 1);
            temp.pop_back();
        }

        if (j - 1 >= 0 && m[i][j - 1] == 1)
        {
            temp += "L";
            helper(m, n, temp, ans, i, j - 1);
            temp.pop_back();
        }

        m[i][j] = 1; // Reset the current cell to unvisited
    }

    vector<string> findPath(vector<vector<int>> &m, int n)
    {
        vector<string> ans;
        string temp = "";
        int i = 0;
        int j = 0;
        if(m[i][j] == 0)
        {
            // ans.push_back(-1);
            return ans;
        }
        helper(m, n, temp, ans, i, j);
        return ans;
    }



    };

        


    //{ Driver Code Starts.

    int main() {
        int t;
        cin >> t;
        while (t--) {
            int n;
            cin >> n;
            vector<vector<int>> m(n, vector<int> (n,0));
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    cin >> m[i][j];
                }
            }
            Solution obj;
            vector<string> result = obj.findPath(m, n);
            sort(result.begin(), result.end());
            if (result.size() == 0)
                cout << -1;
            else
                for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
            cout << endl;
        }
        return 0;
    }
    // } Driver Code Ends