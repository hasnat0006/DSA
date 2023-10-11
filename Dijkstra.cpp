//!-----------------------------------------------------!//
//!                  YUSUF REZA HASNAT                  !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "C:\Users\Yusuf Reza Hasnat\OneDrive\Desktop\CP\debug.h"
#else
#define dbg(x...)
#define dbgc(x...)
#endif

using namespace std;

#define int long long
#define float long double
#define pb push_back
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define dosomic(x) fixed << setprecision(x)
#define endl "\n"
#define case(x) cout << "Case " << x << ": "
#define YUSUF ios_base::sync_with_stdio(false),
#define REZA cin.tie(NULL),
#define HASNAT cout.tie(NULL)

int mod = 1000000007;
float pi = acos(-1);
int inf = 1e18;

map<string, string> par;

void dijkstra(int n, string src, string dest,
              map<string, vector<pair<string, int>>> adj) {
    set<pair<int, string>> s;
    s.insert({0, src});
    map<string, int> dist;
    for (auto i : adj) {
        dist[i.first] = inf;
    }
    dist[src] = 0;
    while (!s.empty()) {
        auto top = *s.begin();
        int Nodedist = top.first;
        string Node = top.second;
        s.erase(s.begin());
        for (auto it : adj[Node]) {
            string adjNode = it.first;
            int adjNodeDist = it.second;
            if (Nodedist + adjNodeDist < dist[adjNode]) {
                auto fnd = s.find({dist[adjNode], adjNode});
                if (fnd != s.end()) {
                    s.erase(fnd);
                }
                dist[adjNode] = Nodedist + adjNodeDist;
                s.insert({dist[adjNode], adjNode});
                par[adjNode] = Node;
            }
        }
    }
    dbg(dist);
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
        adj[v].push_back({u, wt});
    }
    string src, dest;
    cin >> src >> dest;
    dijkstra(n, src, dest, adj);
    dbg(par);
}

int32_t main() {
    YUSUF REZA HASNAT;
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++)
        // case(i)
        solve();
    return 0;
}