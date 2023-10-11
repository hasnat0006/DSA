#include <bits/stdc++.h>
using namespace std;

class Node {
   public:
    int EoW;
    Node *child[60];
    Node() {
        EoW = 0;
        for (int i = 0; i < 60; i++)
            this->child[i] = NULL;
    }
};

void insert(Node *root, string s) {
    for (int i = 0; i < s.size(); i++) {
        int id = s[i] - 'A';
        if (root->child[id] == NULL)
            root->child[id] = new Node();
        root = root->child[id];
    }
    root->EoW++;
}
int search(Node *root, string s) {
    for (int i = 0; i < s.size(); i++) {
        if (root->child[s[i] - 'A'] == NULL)
            return 0;
        root = root->child[s[i] - 'A'];
    }
    return root->EoW;
}
void lexi(Node *root, string s = "") {
    if (root->EoW > 0)
        cout << s << endl;
    for (int i = 0; i < 60; i++) {
        if (root->child[i] != NULL) {
            char temp = i + 'A';
            lexi(root->child[i], s + temp);
        }
    }
}

bool isLeaf(Node *root) {
    for (int i = 0; i <= 60; i++)
        if (root->child[i] != NULL)
            return false;
    return true;
}

int isJunction(Node *root) {
    int cnt = 0;
    for (int i = 0; i < 60; i++) {
        if (root->child[i] != NULL)
            cnt++;
    }
    if (root->EoW > 0 and cnt > 1)
        return 1;
    return 0;
}
void removeEdge(Node *root, char c, int d) {
    if (d == 0)
        return;
    Node *saving = root->child[c - 'A'];
    root->child[c - 'A'] = NULL;
    delete saving;
}

int dlt(Node *root, string s, int k = 0) {
    if (root == NULL)
        return 0;
    if (k == s.size()) {
        if (root->EoW == 0)
            return root->EoW;
        if (!isLeaf(root)) {
            root->EoW = 0;
            return 0;
        }
        return 1;
    }
    int id = s[k] - 'A';
    int d = dlt(root->child[id], s, k + 1);
    int j = isJunction(root);
    removeEdge(root, s[k], d);
    if (j == 1)
        d = 0;
    return d;
}

int main() {}