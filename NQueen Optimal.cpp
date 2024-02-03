// It just count the number of ways to place the order.

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
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"
#define YUSUF ios_base::sync_with_stdio(false),
#define REZA cin.tie(NULL),
#define HASNAT cout.tie(NULL)

const int N = 32;
int mark[N][N];
char grid[N][N];
int n;

int cnt;

void fillup(int row, int col) {
    for (int i = 1; i < n - row + 1; i++) {
        mark[row + i][col]++;
        if (col - i >= 0)
            mark[row + i][col - i]++;
        if (col + i < n)
            mark[row + i][col + i]++;
    }
}

void fillout(int row, int col) {
    for (int i = 1; i < n - row + 1; i++) {
        mark[row + i][col]--;
        if (col - i >= 0)
            mark[row + i][col - i]--;
        if (col + i < n)
            mark[row + i][col + i]--;
    }
}

void find_way(int row) {
    if (row == n) {
        cnt++;
        return;
    }
    for (int j = 0; j < n; j++) {
        if (grid[row][j] == '*' or mark[row][j])
            continue;
        fillup(row, j);
        find_way(row + 1);
        fillout(row, j);
    }
}

void solve(int t) {
    cnt = 0;
    cin >> n;
    if (n == 0)
        exit(0);
    // user defined grid.
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> grid[i][j];
    find_way(0);
    cout << cnt << endl;
}

int32_t main() {
    YUSUF REZA HASNAT;
    int t = 1;
    // cin >> t;
    for (int i = 1;; i++) {
        solve(i);
    }
    return 0;
}
