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

void trie_insert(Node *root, string s) {
    for (int i = 0; i < s.size(); i++) {
        int id = s[i] - 'A';
        if (root->child[id] == NULL)
            root->child[id] = new Node;
        root = root->child[id];
    }
    root->EoW += 1;
}

int trie_search(Node *root, string s) {
    for (int i = 0; i < (int)s.size(); i++) {
        int id = s[i] - 'A';
        if (root->child[id] == NULL)
            return 0;
        root = root->child[id];
    }
    return root->EoW;
}

void Lexicographical_sort(Node *root, string s = "") {
    if (root->EoW > 0)
        cout << s << " - " << root->EoW << endl;
    for (int i = 0; i < 60; i++) {
        if (root->child[i] != NULL) {
            char temp = i + 'A';
            Lexicographical_sort(root->child[i], s + temp);
        }
    }
}

void removeEdge(Node *root, char c, int d) {
    if (d == 0)
        return;
    int r = c - 'A';
    Node *v = root->child[r];
    root->child[r] = NULL;
    delete v;
}

bool isJunction(Node *root) {
    int cnt = 0;
    for (int i = 0; i < 60; i++) {
        if (root->child[i] != NULL) {
            cnt++;
        }
    }
    if (root->EoW > 0 and cnt > 1)
        return true;
    return false;
}

bool isLeaf(Node *root) {
    for (int i = 0; i < 60; i++)
        if (root->child[i] != NULL)
            return false;
    return true;
}

int deleteTrie(Node *root, string s, int k) {
    if (root == NULL)
        return 0;
    if (k == s.length()) {
        if (root->EoW == 0)
            return 0;
        int x = isLeaf(root);
        if (!isLeaf(root)) {
            root->EoW--;
            return 0;
        }
        // else if (isLeaf(root) && root->EoW > 1) {
        //     root->EoW--;
        //     return 0;
        // }
        return 1;
    }
    int id = s[k] - 'A';
    int d = deleteTrie(root->child[id], s, k + 1);
    int j = isJunction(root->child[id]);
    removeEdge(root, s[k], d);
    if (j == 1)
        d = 0;
    return d;
}

int32_t main() {
    Node *trie = new Node;
    while (1) {
        cout << "MENU: \n";
        cout << "1. Insert\n";
        cout << "2. Search\n";
        cout << "3. Delete\n";
        cout << "4. Lexicographical Sorting\n";
        cout << "5. Display String\n";
        cout << "6. End\n";
        int ch;
        string s;
        cout << "Enter your choice: ", cin >> ch;
        if (ch == 1) {
            cout << "String: ", cin >> s;
            trie_insert(trie, s);
            cout << "String inserted\n";
        }
        else if (ch == 2) {
            cout << "String: ", cin >> s;
            if (trie_search(trie, s))
                cout << "String found\n";
            else
                cout << "String not found\n";
        }
        else if (ch == 3) {
            cout << "String: ", cin >> s;
            if (trie_search(trie, s) > 0)
                deleteTrie(trie, s, 0), cout << "String removed\n";
            else
                cout << "String doesnot exit\n";
        }
        else if (ch == 4) {
            Lexicographical_sort(trie);
        }
        else if (ch == 5) {
            Lexicographical_sort(trie);
        }
        else if (ch == 6)
            break;
    }
}

/*
1 MIST
1 MIT
1 CSE
1 CSE
1 CE
1 MISTCSE
1 ME
1 EECE
1 ABC
1 ABC
1 AB
*/