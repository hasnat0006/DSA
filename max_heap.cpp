/// Max Heap

#include <bits/stdc++.h>
using namespace std;

class Heap {
   private:
    int a[101], size;

   public:
    Heap() { size = 0; }

   private:         
    void bottomTopAdjust(int i) {
        while (i > 1) {
            int par = i / 2;
            if (a[par] < a[i]) {
                swap(a[par], a[i]);
                i = i / 2;
            }
            else
                break;
        }
    }
    void topBottomAdjust(int i) {
        int left = 2 * i, right = 2 * i + 1;
        int l;
        if (left <= size and a[left] > a[i])
            l = left;
        else
            l = i;
        if (right <= size and a[right] > a[l])
            l = right;
        if (i != l) {
            swap(a[i], a[l]);
            topBottomAdjust(l);
        }
    }

   public:
    bool insert(int val) {
        if (size == 101) {
            return false;
        }
        a[++size] = val;
        bottomTopAdjust(size);
        return true;
    }

    int showMax() { return a[1]; }

    int showSize() { return size; }

    bool deleteRoot() {
        if (size == 0) {
            return false;
        }
        swap(a[1], a[size--]);
        topBottomAdjust(1);
        return true;
    }

    void buildHeap() {
        int n = size / 2;
        for (int i = n; i > 0; i--) {
            topBottomAdjust(i);
        }
    }

    void sort() {
        int last = size, fix = size;
        for (int i = 1; i < fix; i++) {
            int mx = a[1];
            deleteRoot();
            a[last--] = mx;
        }
        size = fix;
    }

    void bfs() {
        if (size == 0)
            return;
        int level = 2;
        queue<int> q;
        q.push(1);
        while (!q.empty()) {
            int parent = q.front();
            q.pop();
            if (parent == level) {
                cout << endl;
                level = level * 2;
            }
            cout << a[parent] << " ";
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
        cout << "1. Insert\n2. Show Max\n3. Delete Max\n4. Sort\n5. Level\n6. "
                "Build Heap\n7. End"
             << endl
             << endl;
        int choice;
        cin >> choice;

        if (choice == 1) {
            cout << "Insert Value: ";
            int y;
            cin >> y;
            bool b = heap.insert(y);

            if (b)
                cout << y << " is inserted in the heap" << endl;
        }

        else if (choice == 2) {
            if (heap.showSize() != 0)
                cout << "Max Element: " << heap.showMax();
            else
                cout << "No element in the heap" << endl;
        }

        else if (choice == 3) {
            bool b = heap.deleteRoot();
            if (b)
                cout << "Root deleted from heap";
            else
                cout << "Heap is empty";
            cout << endl;
        }

        else if (choice == 4) {
            heap.sort();
        }

        else if (choice == 5) {
            cout << "Level Wise Traversal of the heap:" << endl;
            heap.bfs();
            cout << endl;
        }
        else if (choice == 6) {
            if (heap.showSize() == 0)
                cout << "Heap is Empty!" << endl;
            else
                heap.buildHeap();
        }
        else if (choice == 7) {
            break;
        }

        else {
            cout << "Invalid Choice" << endl;
        }
        cout << endl;
    }
}

/*
1 2
1 9
1 8
1 16
1 3
1 7
1 10
1 1
1 4
1 14



1 14
1 9
1 10
1 4
1 3
1 7
1 8
1 1
1 2
*/
