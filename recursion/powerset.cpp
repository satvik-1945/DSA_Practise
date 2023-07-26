//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
public:
    void helper(vector<string> &ans, string &s, int i, string &temp)
{
    if (i == s.size())
    {
        ans.push_back(temp);
        return;
    }
    temp.push_back(s[i]);
    helper(ans, s, i + 1, temp);
    temp.pop_back();
    helper(ans, s, i + 1, temp);
}

vector<string> AllPossibleStrings(string s)
{
    vector<string> ans;
    int i = 0;
    string temp;
    helper(ans, s, i, temp);
    sort(ans.begin(), ans.end());
    // ans.erase(unique(ans.begin(), ans.end()), ans.end());
    vector<string> to(ans.size()-1) ;
    for(int i = 0 ; i< ans.size()-1; i++)
    {
        to[i] = ans[i+1];
    }
    return to;
}

};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}
// } Driver Code Ends