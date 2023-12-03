#include <bits/stdc++.h>
using namespace std;

int edges;
map<string, vector<string>> adj;
map<string, int> degree;
set<string> nodes;
vector<string> ans;
int cnt = 0;

void all_possible_way(vector<string> current = {}) {
    int f = 0;
    for (auto i : nodes) {
        if (degree[i] == 0) {
            f = 1;
            degree[i] = -1;
            current.push_back(i);
            for (auto j : adj[i])
                degree[j]--;
            all_possible_way(current);
            degree[i] = 0;
            current.pop_back();
            for (auto j : adj[i])
                degree[j]++;
        }
    }
    if (!f and current.size() == nodes.size()) {
        for (auto i : current)
            cout << i << " ";
        cout << endl;
        cnt++;
    }
}

int main() {
    int n;
    cin >> edges;
    for (int i = 0; i < edges; i++) {
        string u, v;
        cin >> u >> v;
        if (u == "0" and v == "0")
            break;
        adj[u].push_back(v);
        degree[v]++;
        nodes.insert(u);
        nodes.insert(v);
    }
    // topo_sort();
    all_possible_way();
    if (cnt == 0) {
        cout << "Cycle exist!\n";
    }
}

/*

8
A D
B D
B C
C E
C F
D E
D F
E B
*/
