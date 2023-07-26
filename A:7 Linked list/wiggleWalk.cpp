#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
const int N = 200005;

struct Node
{
    pair<int,int> N, S, W, E;
    Node()
    {
        N = S = E = W = {0, 0};
    }
    Node(int x, int y)
    {
        N = {x - 1, y};
        S = {x + 1, y};
        E = {x, y + 1};
        W = {x, y - 1};
    }
};
void solve(int cc)
{
    int n, r, c;
    cin >> n >> r >> c;
    int sr, sc;
    cin >> sr >> sc;
    string s;
    cin >> s;
    map<pair<int, int>, Node> m;
    Node curr = Node(sr, sc);
    m[{sr, sc}] = curr;
    for (int i = 0; i < s.length(); i++)
    {
        if (m.find({sr, sc}) == m.end())
        {
            m[{sr, sc}] = Node(sr, sc);
        }
        auto n = m[{sr, sc}].N;
        auto ss = m[{sr, sc}].S;
        auto w = m[{sr, sc}].W;
        auto e = m[{sr, sc}].E;
        if (m.find(n) == m.end())
            m[n] = Node(n.first, n.second);
        if (m.find(ss) == m.end())
            m[ss] = Node(ss.first, ss.second);
        if (m.find(e) == m.end())
            m[e] = Node(e.first, e.second);
        if (m.find(w) == m.end())
            m[w] = Node(w.first, w.second);

        m[n].S = ss;
        m[ss].N = n;
        m[e].W = w;
        m[w].E = e;
        if (s[i] == 'E')
            sc = e.second;
        else if (s[i] == 'W')
            sc = w.second;
        else if (s[i] == 'S')
            sr = ss.first;
        else
            sr = n.first;
    }
    cout << "Case #" << cc << ": " << sr << " " << sc << endl;
}
int32_t main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int t = 1;
cin >> t;
for(int i=1; i<=t; i++)solve(i);
return 0;
}