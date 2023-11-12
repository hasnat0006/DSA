#include <bits/stdc++.h>
using namespace std;

int edges;
map<string, vector<string>> adj;
map<string, int> degree;
set<string> nodes;
vector<string> ans;
int c = 0;

void topo_sort() {
    queue<string> qu;
    // traverse all the nodes and check it's degree is 0 or not..
    for (string i : nodes) {
        if (degree[i] == 0) {
            qu.push(i);
        }
    }
    while (!qu.empty()) {
        string top = qu.front();
        qu.pop();
        ans.push_back(top);
        for (string i : adj[top]) {
            degree[i]--;
            if (degree[i] == 0) {
                qu.push(i);
            }
        }
    }
}

int main() {
    cout << "Number of edges: ", cin >> edges;
    for (int i = 0; i < edges; i++) {
        string u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        degree[v]++;
        nodes.insert(u);
        nodes.insert(v);
    }
    topo_sort();
    if (nodes.size() == ans.size()) {
        // ans exist.. no cycle found.
        cout << "[ ";
        for (auto i : ans)
            cout << i << " ";
        cout << "]\n";
    }
    else {
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