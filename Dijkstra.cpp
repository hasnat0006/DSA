//!-----------------------------------------------------!//
//!                  YUSUF REZA HASNAT                  !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9;

void dijkstra(int n, string src, string dest,
              map<string, vector<pair<string, int>>> &adj,
              map<string, string> &par) {
    set<pair<int, string>> s;
    s.insert({0, src});
    map<string, int> dist;
    for (auto i : adj) {
        dist[i.first] = inf;
    }
    dist[src] = 0;
    while (!s.empty()) {
        auto top = *s.begin();
        int nodeDis = top.first;
        string topNode = top.second;
        s.erase(s.begin());
        for (auto it : adj[topNode]) {
            string adjNode = it.first;
            int adjWt = it.second;
            if (nodeDis + adjWt < dist[adjNode]) {
                dist[adjNode] = nodeDis + adjWt;
                s.insert({dist[adjNode], adjNode});
                par[adjNode] = topNode;
            }
        }
    }
}

int32_t main() {
    int n, m;
    cin >> n >> m;
    map<string, vector<pair<string, int>>> adj;
    map<string, string> parent;
    for (int i = 0; i < m; i++) {
        string u, v;
        int wt;
        cin >> u >> v >> wt;
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }
    string src, dest;
    cin >> src >> dest;
    dijkstra(n, src, dest, adj, parent);
    vector<string> path;
    path.push_back(dest);
    string temp = parent[dest];
    while (temp != src) {
        path.push_back(temp);
        temp = parent[temp];
    }
    path.push_back(src);
    reverse(path.begin(), path.end());
    for (auto i : path)
        cout << i << " ";
    cout << endl;
}