//!-----------------------------------------------------!//
//!                  YUSUF REZA HASNAT                  !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "C:\Users\Yusuf Reza Hasnat\OneDrive\Desktop\CP\debug.h"
#else
#define dbg(x...)
#define dbgc(x...)
#endif

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

int arr[2][10000];  // todo -> 0 index = wt, 1 index = value;
int dp[10005][10005], mark[10005][10005];

void print_items(int i, int wt) {
    if (i == 0)
        return;
    if (mark[i][wt] == 1) {
        dbg(i, wt);
        print_items(i - 1, wt - arr[0][i]),
            cout << arr[0][i] << " " << arr[1][i] << endl;
    }
    else if (mark[i][wt] == 2)
        print_items(i - 1, wt);
}
//todo --> all the calculation is 1 base indexing..
void solve() {
    int item, totalWt;
    cin >> item >> totalWt;
    for (int i = 1; i <= item; i++) {
        //! -> wt        -> value
        cin >> arr[0][i] >> arr[1][i];
    }
    for (int i = 1; i <= item; i++) {
        for (int j = 1; j <= totalWt; j++) {
            int nibona = dp[i - 1][j];
            int nibo{0};
            if (j >= arr[0][i]) {
                nibo = arr[1][i] + dp[i - 1][j - arr[0][i]];
            }
            if (nibo >= nibona)
                mark[i][j] = 1;
            else
                mark[i][j] = 2;
            dp[i][j] = max(nibo, nibona);
        }
    }
    cout << dp[item][totalWt] << endl;
    cout << "Taken items:\n", print_items(item, totalWt);
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
