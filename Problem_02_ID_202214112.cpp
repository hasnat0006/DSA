#include <bits/stdc++.h>
using namespace std;

class Pair {
    int key, val;

   public:
    Pair() { key = val = 0; }
    Pair(int a, int b) { key = a, val = b; }
    int get_Key() { return key; }
    int get_Value() { return val; }
    void set_key(int key) { this->key = key; }
};

class Heap {
   private:
    Pair *a = new Pair[101];
    int size;

   public:
    Heap() { size = 0; }

   private:
    void bottomTopAdjust(int i) {
        while (i != 1) {
            if (a[i].get_Key() < a[i / 2].get_Key())
                swap(a[i], a[i / 2]);
            else
                break;
            i = i / 2;
        }
    }
    void topBottomAdjust(int i) {
        int left = 2 * i, right = 2 * i + 1, l;
        if (left <= size and a[left].get_Key() < a[i].get_Key())
            l = left;
        else
            l = i;
        if (right <= size and a[right].get_Key() < a[l].get_Key())
            l = right;
        if (i != l) {
            swap(a[i], a[l]);
            topBottomAdjust(l);
        }
    }
    void buildHeap() {
        int n = size / 2;
        for (int i = n; i > 0; i--) {
            topBottomAdjust(i);
        }
    }

   public:
    bool insert(int key, int val) {
        if (size == 101)
            return false;
        a[++size] = Pair(key, val);
        bottomTopAdjust(size);
        return true;
    }
    bool increaseKey(int x, int k) {
        if (x > size)
            return false;
        a[x].set_key(k);
        buildHeap();
        return true;
    }
    int showMax() { return a[1].get_Value(); }

    int showSize() { return size; }

    void deleteRoot() {
        swap(a[1], a[size--]);
        topBottomAdjust(1);
    }
    int extractMax() {
        int mx = a[1].get_Value();
        deleteRoot();
        return mx;
    }

    void bfs() {
        if (size == 0)
            return;
        int level = 2;
        queue<int> q;
        q.push(1);
        cout << "[ Key, Value ]" << endl;
        while (!q.empty()) {
            int parent = q.front();
            q.pop();
            if (parent == level) {
                cout << endl;
                level = level * 2;
            }
            cout << "[ " << a[parent].get_Key() << ", " << a[parent].get_Value() << " ]";
            if (2 * parent <= size)
                q.push(2 * parent);
            if (2 * parent + 1 <= size)
                q.push(2 * parent + 1);
        }
    }
};

int main() {
    Heap heap;

    while (1) {
        cout << "  MENU:\n1. Insert\n2. Increase Key\n3. Show Max\n4. Extract "
                "Max\n"
                "5. Level Order Traversal\n6. End\n";
        int choice;
        cin >> choice;
        if (choice == 1) {
            cout << "Insert Key: ";
            int x, y;
            cin >> x;
            cout << "Insert Value: ";
            cin >> y;
            bool b = heap.insert(x, y);
            if (b)
                cout << y << " is inserted in the heap" << endl;
        }
        else if (choice == 2) {
            cout << "Which node you want to increase?" << endl;
            int nodeNo;
            cin >> nodeNo;
            cout << "What will be the new key value?" << endl;
            int key;
            cin >> key;
            bool b = heap.increaseKey(nodeNo, key);
            if (b)
                cout << "Node key increased successfully!" << endl;
            else
                cout << "Unsuccessful Operation :(" << endl;
        }
        else if (choice == 3) {
            if (heap.showSize() != 0)
                cout << "Max Element: " << heap.showMax();
            else
                cout << "No element in the heap" << endl;
        }
        else if (choice == 3) {
            if (heap.showSize() != 0)
                cout << "Max Element: " << heap.showMax();
            else
                cout << "No element in the queue" << endl;
        }
        else if (choice == 4) {
            if (heap.showSize() != 0)
                cout << "Max element extracted: " << heap.extractMax();
            else
                cout << "No element in the queue" << endl;
        }
        else if (choice == 5) {
            if (heap.showSize() != 0) {
                cout << "Level Wise Traversal of the Queue:" << endl;
                heap.bfs();
                cout << endl;
            }
            else
                cout << "No element in the queue" << endl;
        }
        else if (choice == 6)
            break;
        else {
            cout << "Invalid Choice" << endl;
        }
        cout << endl;
    }
}

/*
1 10 2
1 4 9
1 3 8
1 2 16
1 5 3
1 8 7
1 7 10
1 1 1
1 6 4
1 9 14
*/
