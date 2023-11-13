//!-----------------------------------------------------!//
//!                  YUSUF REZA HASNAT                  !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

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
