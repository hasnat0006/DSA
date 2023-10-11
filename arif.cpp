#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false), cin.tie(nullptr);
#define int long long
#define endl "\n"
int partition(int ar[], int s, int e) {
    int pivot = ar[e];
    // int sum;
    int index = s;
    for (int i = s; i < e; i++) {
        if (ar[i] < pivot) {
            swap(ar[i], ar[index]);
            index++;
        }
    }
    swap(ar[e], ar[index]);
    return index;
}

void quick(int ar[], int s, int e, int n) {
    if (s < e) {
        int p = partition(ar, s, e);
        quick(ar, s, p - 1, n);
        quick(ar, p + 1, e, n);
        if (p == n)
            cout << ar[p];
    }
}
int32_t main() {
    fastio;
    int ar[9] = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    int k = 6;
    int n = 9 - 6;

    quick(ar, 0, 8, n);
}