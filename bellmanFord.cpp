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

void bellmonFord(int n, string src, string dest,
                 map<string, vector<pair<string, int>>> adj) {
    map<string, int> dist;
    map<string, string> parent;
    for (auto i : adj)
        dist[i.first] = inf;
    dist[src] = 0;
    dbg(dist);
    for (int step = 0; step < n; step++) {
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
    reverse(vf(path));
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
    dbg(adj);
    string src, dest;
    cin >> src >> dest;
    bellmonFord(n, src, dest, adj);
}

int32_t main() {
    YUSUF REZA HASNAT;
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
hasnat
*/