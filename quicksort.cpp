#include <bits/stdc++.h>
using namespace std;

int arr[1000];

int partition(int low, int high) {
    int i = low, j = high, pivot = arr[low];
    while (i < j) {
        while (arr[i] <= pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i < j)
            swap(arr[i], arr[j]);
    }
    swap(arr[low], arr[j]);
    return j;
}

// int partition(int low, int high) {
//     int i = low, pivot = arr[low];
//     for (int k = low; k < high; k++) {
//         if (arr[k] > pivot) {
//             swap(arr[i++], arr[k]);
//         }
//     }
//     swap(arr[i], arr[high]);
//     return i;
// }

void QuickSort(int low, int high) {
    if (low < high) {
        int pivot = partition(low, high);
        QuickSort(low, pivot - 1);
        QuickSort(pivot + 1, high);
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    QuickSort(0, n - 1);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}