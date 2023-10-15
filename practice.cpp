#include <bits/stdc++.h>
using namespace std;

class Node {
   public:
    int EoW;
    Node *child[30];
    Node() {
        EoW = 0;
        for (int i = 0; i < 30; i++) {
            this->child[i] = NULL;
        }
    }
};

void insert(Node *root, string s) {
    for (int i = 0; i < s.size(); i++) {
        int id = s[i] - 'A';
        if (root->child[id] == NULL)
            root->child[id] = new Node;
        root = root->child[id];
    }
    root->EoW++;
}

bool search(Node *root, string s) {
    for (int i = 0; i < s.size(); i++) {
        int id = s[i] - 'A';
        if (root->child[id] == NULL)
            return false;
    }
    int f = 1;
    root->EoW > 0 ? f = 1 : f = 0;
    return f;
}

void print_trie(Node *root, string s = "") {
    if (root->EoW)
        cout << s << endl;
    for (int i = 0; i < 30; i++) {
        if (root->child[i] != NULL) {
            char temp = i + 'A';
            print_trie(root->child[i], s + temp);
        }
    }
}

bool isLeaf(Node *root) {
    for (int i = 0; i < 30; i++)
        if (root->child[i] != NULL)
            return false;
    return true;
}

int isJunction(Node *root) {
    int cnt = 0;
    for (int i = 0; i < 30; i++)
        if (root->child[i] != NULL)
            cnt++;
    if (cnt > 1 and root->EoW > 0)
        return 1;
    return 0;
}

void removeEdge(Node *root, char c, int d) {
    if (d == 0)
        return;
    int r = c - 'A';
    Node *v = root->child[r];
    root->child[r] = NULL;
    delete v;
}

int dlt(Node *root, string s, int k = 0) {
    if (root == NULL)
        return 0;
    if (s.size() == k) {
        if (root->EoW) {
            root->EoW = 0;
            int x = isLeaf(root);
            if (x)
                return 1;
            else
                return 0;
        }
    }
    int id = s[k] - 'A';
    int d = dlt(root->child[id], s, k + 1);
    int j = isJunction(root->child[id]);
    removeEdge(root, s[k], j);
    if (j)
        d = 0;
    return d;
}

int main() {}