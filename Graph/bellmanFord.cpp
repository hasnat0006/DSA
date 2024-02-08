//!-----------------------------------------------------!//
//!                  YUSUF REZA HASNAT                  !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define int long long
int inf = 1e18;

void bellmonFord(int n, string src, string dest, map<string, vector<pair<string, int>>> &adj) {
    map<string, int> dist;
    map<string, string> parent;
    for (auto i : adj)
        dist[i.first] = inf;
    dist[src] = 0;
    for (int step = 0; step < n - 1; step++) {
        for (auto i : adj) {
            for (auto it : adj[i.first]) {
                string u = i.first;
                string v = it.first;
                int wt = it.second;
                if (dist[u] != inf && dist[u] + wt < dist[v]) {
                    dist[v] = dist[u] + wt;
                    parent[v] = u;
                }
            }
        }
    }
    vector<string> path;
    while (dest != src) {
        path.push_back(dest);
        dest = parent[dest];
    }
    path.push_back(src);
    for (auto i : dist)
        cout << i.first << " " << i.second << endl;
    reverse(path.begin(), path.end());
    for (auto i : path)
        cout << i << " -> ";
}

void solve() {
    int n, m;
    cin >> n >> m;
    map<string, vector<pair<string, int>>> adj;
    for (int i = 0; i < m; i++) {
        string u, v;
        int wt;
        cin >> u >> v >> wt;
        adj[u].push_back({v, wt});
    }
    string src, dest;
    cin >> src >> dest;
    bellmonFord(n, src, dest, adj);
}

int32_t main() {
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++)
        // case(i)
        solve();
    return 0;
}

/*

5 7
hasnat raisul 2
raisul ifrit 1
ifrit zaima 3
hasnat ifrit 4
raisul nabiha 7
nabiha zaima 1
zaima hasnat -7
src des
*/