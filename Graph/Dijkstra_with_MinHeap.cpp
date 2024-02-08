//!-----------------------------------------------------!//
//!                  YUSUF REZA HASNAT                  !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>
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

class Heap {
   public:
    vector<pair<int, int>> arr;
    int size;
    Heap() {
        size = 0;
        arr.resize(100001);
    }
    void bottomTopAdjust(int i) {
        while (i > 1) {
            int par = i / 2;
            if (arr[par].first > arr[i].first)
                swap(arr[par], arr[i]), i /= 2;
            else
                break;
        }
    }
    void topBottomAdjust(int i) {
        int left = i * 2, right = i * 2 + 1, l;
        if (left <= size and arr[left].first < arr[i].first)
            l = left;
        else
            l = i;
        if (right <= size and arr[right].first < arr[l].first)
            l = right;
        if (l != i) {
            swap(arr[i], arr[l]);
            topBottomAdjust(l);
        }
    }
    void insert(pair<int, int> val) {
        arr[++size] = val;
        bottomTopAdjust(size);
    }
    pair<int, int> showMin() { return arr[1]; }
    int Heapsize() { return size; }
    void buildHeap() {
        int n = size / 2;
        for (int i = n; i > 0; i--) {
            topBottomAdjust(i);
        }
    }
    bool deleteRoot() {
        if (size == 0)
            return false;
        swap(arr[1], arr[size--]);
        topBottomAdjust(1);
        return true;
    }
};

vector<pair<int, int>> adj[100001];
vector<int> cost(100001, inf);
vector<int> parent(100001, -1);

void Dijkstra(int n, int src) {
    Heap heap;
    heap.insert({0, src});
    cost[src] = 0;
    while (heap.Heapsize()) {
        auto top = heap.showMin();
        int nodeDis = top.first;
        int topNode = top.second;
        heap.deleteRoot();
        for (auto it : adj[topNode]) {
            int adjNode = it.first;
            int adjWt = it.second;
            if (nodeDis + adjWt < cost[adjNode]) {
                cost[adjNode] = nodeDis + adjWt;
                heap.insert({cost[adjNode], adjNode});
                parent[adjNode] = topNode;
            }
        }
    }
}

void solve() {
    int node, edge, u, v, wt;
    cin >> node >> edge;
    for (int i = 0; i < edge; i++) {
        cin >> u >> v >> wt;
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }
    int src = 1;
    // cin >> src;
    // here we go 1 to node
    Dijkstra(node, src);
    vector<int> path;
    while (node != src) {
        path.pb(node);
        node = parent[node];
    }
    path.push_back(src);
    reverse(vf(path));
    for (auto i : path) {
        cout << i << " ";
    }
    cout << endl;
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