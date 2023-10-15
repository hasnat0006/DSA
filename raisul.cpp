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

vector<pair<int, int>> adj[10005];
vector<int> parent(10005), cost(10005, inf);

void Dijkstra(int n, int src) {
    cost[src] = 0;
    for(int i = 1; i < n; i++){
        for(int i = 1; i <= n; i++){
            for(auto it : adj[i]){
                int u = i;
                int v = it.first;
                int wt = it.second;
                if(cost[u] != inf and cost[u] + wt < cost[v]){
                    cost[v] = cost[u] + wt;
                    parent[v] = u;
                }
            }
        }
    }
}

void solve() {
    int node, edge;
    cin >> node >> edge;
    for (int i = 0; i < edge; i++) {
        int u, v, wt;
        cin >> u >> v >> wt;
        adj[u].push_back({v, wt});
        // adj[v].push_back({u, wt});
    }
    int src, des;
    cin >> src >> des;
    Dijkstra(node, src);
    vector<int> path;
    while (des != src) {
        path.pb(des);
        des = parent[des];
    }
    path.pb(src);
    reverse(vf(path));
    dbg(path);
    // dbg(cost);
}

int32_t main() {
    YUSUF REZA HASNAT;
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        // case(i)
        solve();
    }
    return 0;
}