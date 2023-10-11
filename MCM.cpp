
#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
int d[N];
int dp[N][N], mark[N][N];

int MCM(int i, int j) {
    if (i == j)
        return dp[i][j] = 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    int mn = INT_MAX;
    for (int k = i; k < j; k++) {
        int x = mn;
        mn = min(mn, MCM(i, k) + MCM(k + 1, j) + d[i - 1] * d[k] * d[j]);
        if (x != mn)
            mark[i][j] = k;
    }
    return dp[i][j] = mn;
}

void print(int i, int j) {
    if (i == j)
        cout << "A" << i;
    else {
        cout << "(", print(i, mark[i][j]), print(mark[i][j] + 1, j),
            cout << ")";
    }
}

int main() {
    memset(dp, -1, sizeof dp);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> d[i];
    }
    cout << MCM(1, n - 1) << "\n";
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) {
    //         cout << mark[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    print(1, n - 1);
}