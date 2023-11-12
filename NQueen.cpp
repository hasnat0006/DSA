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

const int N = 1005;
int mark[N][N];
int n;

bool isValid(int row, int col) {
    for (int i = row; i > 0; i--) {
        if (mark[i][col])
            return false;
    }
    for (int i = row, j = col; i > 0 and j > 0; i--, j--) {
        if (mark[i][j])
            return false;
    }
    for (int i = row, j = col; i > 0 and j <= n; i--, j++) {
        if (mark[i][j])
            return false;
    }
    return true;
}

void print_way() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (mark[i][j])
                cout << "Q";
            else
                cout << ".";
        }
        cout << endl;
    }
    for (int i = 1; i <= n; i++)
        cout << "-";
    cout << endl;
}

int cnt;
void find_way(int row) {
    if (row == n + 1) {
        cnt++;
        print_way();
        return;
    }
    for (int j = 1; j <= n; j++) {
        if (isValid(row, j)) {
            mark[row][j] = 1;
            find_way(row + 1);
            mark[row][j] = 0;
        }
    }
}

void solve() {
    cin >> n;
    find_way(1);
    cout << cnt << endl;
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