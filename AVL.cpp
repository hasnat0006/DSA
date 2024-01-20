#include <bits/stdc++.h>
using namespace std;

class Node {
   public:
    Node *right, *left;
    int val, height;
    Node() {
        right = left = NULL;
        val = 0, height = 0;
    }
    Node(int n) {
        right = left = NULL;
        val = n, height = 0;
    }
};

class AVL {
    Node *root;

   public:
    AVL() { root = NULL; }
    Node *get_root() { return root; }
    int findHeight(Node *u) { return (u == NULL) ? -1 : u->height; }
    void LeftRotation(Node *&u) {
        Node *v = u->right;
        u->right = v->left;
        v->left = u;
        u->height = max(findHeight(u->right), findHeight(u->left)) + 1;
        v->height = max(findHeight(v->left), findHeight(v->right)) + 1;
        u = v;
    }
    void RightRotation(Node *&u) {
        Node *v = u->left;
        u->left = v->right;
        v->right = u;
        u->height = max(findHeight(u->right), findHeight(u->left)) + 1;
        v->height = max(findHeight(v->right), findHeight(v->left)) + 1;
        u = v;
    }
    void LeftRightRotation(Node *&u) {
        LeftRotation(u->left);
        RightRotation(u);
    }
    void RightLeftRotation(Node *&u) {
        RightRotation(u->right);
        LeftRotation(u);
    }
    void balance(Node *u) {
        if (u == NULL)
            return;
        if (findHeight(u->left) - findHeight(u->right) > 1) {
            findHeight(u->left->left) >= findHeight(u->left->right)
                ? RightRotation(u)
                : LeftRightRotation(u);
        }
        else if (findHeight(u->right) - findHeight(u->left) > 1) {
            findHeight(u->right->right) >= findHeight(u->right->left)
                ? LeftRotation(u)
                : RightLeftRotation(u);
        }
        u->height = max(findHeight(u->left), findHeight(u->right)) + 1;
    }
    void insert(int n, Node *&u) {
        if (u == NULL)
            u = new Node(n);
        else if (n < u->val)
            insert(n, u->left);
        else if (n > u->val)
            insert(n, u->right);
        balance(u);
    }
    void print_in_order(Node *it) {
        if (it == NULL)
            return;
        print_in_order(it->left);
        cout << it->val << " ";
        print_in_order(it->right);
    }
    Node *find_minimum(Node *it) {
        while (it != NULL)
            it = it->left;
        return it;
    }
    void *delete_element(int n, Node *it) {
        if (it == NULL)
            return it;
        else if (n < it->val) {
            delete_element(n, it->left);
        }
        else if (n > it->val) {
            delete_element(n, it->right);
        }
        else if (it->left != NULL and it->right != NULL) {
            it->val = find_minimum(it->right)->val;
            delete_element(it->val, it->right);
        }
        else {
            Node *oldNode = it;
            it = (it->left != NULL) ? it->left : it->right;
            delete oldNode;
        }
    }
};

int main() {
    AVL b;
    Node *root = b.get_root();
    b.insert(10, root);
    b.insert(7, root);
    b.insert(2, root);
    b.insert(5, root);
    b.insert(20, root);
    b.insert(15, root);
    b.insert(25, root);
    b.print_in_order(b.get_root());
    return 0;
}
