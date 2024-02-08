//!-----------------------------------------------------!//
//!                  YUSUF REZA HASNAT                  !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>


using namespace std;

#define int long long
#define float long double

#define pb push_back
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define dosomic(x) fixed << setprecision(x)
#define endl "\n"
#define case(x) cout << "Case " << x << ": "
#define YUSUF ios_base::sync_with_stdio(false),
#define REZA cin.tie(NULL),
#define HASNAT cout.tie(NULL)

int mod = 1000000007;
float pi = acos(-1);
int inf = 1e18;

vector<int> v;

void marge(int low, int mid, int high) {
    int i = low, j = mid + 1, k = 0;
    vector<int> temp(10000);
    while (i <= mid && j <= high) {
        if (v[i] <= v[j])
            temp[k++] = v[i++];
        else
            temp[k++] = v[j++];
    }
    while (i <= mid)
        temp[k++] = v[i++];
    while (j <= high)
        temp[k++] = v[j++];
    for (int i = 0; i < k; i++) {
        v[low + i] = temp[i];
    }
}

void margeSort(int low, int high) {
    if (low == high)
        return;
    int mid = (low + high) / 2;
    margeSort(low, mid);
    margeSort(mid + 1, high);
    marge(low, mid, high);
}

void solve() {
    int n;
    cin >> n;
    v.resize(n);
    for (auto &i : v)
        cin >> i;
    dbg(v);
    margeSort(0, n - 1);
    dbg(v);
}

int32_t main() {
    YUSUF REZA HASNAT;
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        // case(i)
        solve();
    }
    return 0;
}