#include <bits/stdc++.h>
using namespace std;

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
