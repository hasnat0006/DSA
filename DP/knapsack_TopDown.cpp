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

int arr[2][10000];  // todo -> 0 index = wt, 1 index = value;
int dp[10005][10005], mark[10005][10005];

int knapsack(int i, int wt) {
    if (i < 0 or wt == 0)
        return 0;
    if (dp[i][wt] != -1)
        return dp[i][wt];
    int nibona = knapsack(i - 1, wt), nibo = 0;
    if (wt >= arr[0][i])
        nibo = knapsack(i - 1, wt - arr[0][i]) + arr[1][i];
    if (nibo >= nibona)
        mark[i][wt] = 1;
    else
        mark[i][wt] = 2;
    return dp[i][wt] = max(nibo, nibona);
}

void print_items(int i, int wt) {
    if (i < 0)
        return;
    if (mark[i][wt] == 1) {
        dbg(i, wt);
        print_items(i - 1, wt - arr[0][i]),
            cout << arr[0][i] << " " << arr[1][i] << endl;
    }
    else if (mark[i][wt] == 2)
        print_items(i - 1, wt);
}
//todo --> all the calculation is 0 base indexing..
void solve() {
    memset(dp, -1, sizeof dp);
    int item, totalWt;
    cin >> item >> totalWt;
    for (int i = 0; i < item; i++) {
        //! -> wt        -> value
        cin >> arr[0][i] >> arr[1][i];
    }
    cout << knapsack(item - 1, totalWt) << endl;
    print_items(item - 1, totalWt);
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