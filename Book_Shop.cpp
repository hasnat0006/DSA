//!-----------------------------------------------------!//
//!                  YUSUF REZA HASNAT                  !//
//!-----------------------------------------------------!//

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

int dp[1001][1001];
int knapsack(int i, int wt, vector<pair<int, int>> v){
    if(i < 0 or wt <= 0)
        return 0;
    if(dp[i][wt] != -1)
        return dp[i][wt];
    int nibo_na = knapsack(i - 1, wt, v);
    int nibo = 0;
    if(wt >= v[i].first)
        nibo = knapsack(i -1, wt - v[i].first, v) + v[i].second;
    return dp[i][wt] = max(nibo, nibo_na);
}

void solve() {
    int n, wt, x, y;
    cin >> n >> wt;
    memset(dp, -1, sizeof(dp));
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].first;
    }
    for (int i = 0; i < n; i++) {
        cin >> v[i].second;
    }
    cout << knapsack(n - 1, wt, v) << endl;
}

int32_t main() {
    YUSUF REZA HASNAT;
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++)
        // case(i)
        solve();
    return 0;
}