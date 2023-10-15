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
int dp[1000][1000], mark[1000][1000];

void print_string(int i, int j, string a) {
    if (i == 0 or j == 0)
        return;
    if (mark[i][j] == 1)
        print_string(i - 1, j - 1, a), cout << a[i - 1];
    else if (mark[i][j] == 2)
        print_string(i - 1, j, a);
    else if (mark[i][j] == 3)
        print_string(i, j - 1, a);
}

void solve() {
    string a, b;
    cin >> a >> b;
    int n = a.size(), m = b.size();
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i - 1] == b[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1], mark[i][j] = 1; //todo -> 1 for diagonal
            else {
                dp[i - 1][j] > dp[i][j - 1] ? mark[i][j] = 2 : mark[i][j] = 3; //todo -> 2 for top, 3 for left;
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    cout << dp[n][m] << endl;
    print_string(n, m, a);
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