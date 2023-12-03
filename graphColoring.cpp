#include <bits/stdc++.h>
using namespace std;

int clr;
map<string, vector<string>> adj;
set<map<string, int>> ans;
vector<string> nodes;

bool isSafe(string s, int clr, map<string, int> color) {
    for (auto child : adj[s])
        if (color[child] == clr)
            return false;
    return true;
}

void coloring(int idx, int total_clr, map<string, int> color = {}) {
    if (color.size() == adj.size()) {
        ans.insert(color);
        return;
    }
    for (int i = 1; i <= total_clr; i++) {
        if (isSafe(nodes[idx], i, color)) {
            color[nodes[idx]] = i;
            coloring(idx + 1, total_clr, color);
            color.erase(nodes[idx]);
        }
    }
}

int main() {
    int edges;
    cout << "Number of edges: ", cin >> edges;
    string u, v;
    set<string> temp;
    for (int i = 0; i < edges; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        temp.insert(v);
        temp.insert(u);
    }
    for (auto i : temp)
        nodes.push_back(i);
    for (int i = 2; i <= 100; i++) {
        coloring(0, i);
        if (ans.size()) {
            cout << "Minimum number of color required: " << i << endl;
            for (auto i : ans) {
                for (auto it : i) {
                    cout << it.first << " -> " << it.second << endl;
                }
                cout << "------\n\n";
            }
            exit(0);
        }
        ans.clear();
    }
}
