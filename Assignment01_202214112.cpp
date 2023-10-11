#include <bits/stdc++.h>
using namespace std;

const int N = 10000;
int arr[N];

int partition(int low, int high) {
    int i = low, pivot = arr[high];
    for (int k = low; k < high; k++) {
        if (arr[k] >= pivot) {
            swap(arr[i], arr[k]);
            i++;
        }
    }
    swap(arr[i], arr[high]);
    return i;
}

void Quicksort(int low, int high, int k) {
    int pivot = partition(low, high);
    if (pivot == k) {
        cout << k + 1 << "th largest element is: " << arr[pivot] << endl;
        return;
    }
    if (k < pivot)
        Quicksort(low, pivot - 1, k);
    else
        Quicksort(pivot + 1, high, k);
}

int main() {
    int n, k;
    cout << "Enter the value of n: ",
    cin >> n;
    cout << "Enter array element: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << "Enter the value of k: ", cin >> k;
    Quicksort(0, n - 1, k - 1);
}