//!-----------------------------------------------------!//
//!                  YUSUF REZA HASNAT                  !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

int clr;
map<string, vector<string>> adj;
map<map<string, int>, int> ans;

bool isSafe(string child, int clr, map<string, int> color) {
    if (color[child])
        return false;
    for (auto i : adj[child]) {
        if (color[i] == clr)
            return false;
    }
    return true;
}

void dfs(string start, int total_clr, map<string, int> color) {
    if (color.size() == adj.size()) {
        // for (auto i : color)
        //     cout << i.first << " -> " << i.second << endl;
        // cout << "-------\n\n";
        ans[color]++;
        return;
    }
    for (int i = 1; i <= total_clr; i++) {
        if (isSafe(start, i, color)) {
            color[start] = i;
            for (auto child : adj[start])
                dfs(child, total_clr, color);
            color.erase(start);
        }
    }
}

void coloring(string start, int clr) {
    map<string, int> color;
    dfs(start, clr, color);
}

void solve() {
    int edges;
    cout << "Number of edges: ", cin >> edges;
    string u, v;
    for (int i = 0; i < edges; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cout << "Number of color you have: \n", cin >> clr;
    coloring(u, clr);
    cout << ans.size() << "\n";
    for (auto i : ans) {
        for (auto it : i.first) {
            cout << it.first << " -> " << it.second << endl;
        }
        cout << "------\n\n";
    }
}

int32_t main() {
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        // case(i)
        solve();
    }
    return 0;
}

/*

7
0 1
1 2
1 4
0 4
2 4
4 3
2 3

*/