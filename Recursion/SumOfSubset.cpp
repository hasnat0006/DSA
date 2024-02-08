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

int n, sum;
vector<int> v;

void find_way(int i, int target_sum, vector<int> ans = {}) {
    if (target_sum == 0 and i == n) {
        cout << "[ ";
        for (auto i : ans)
            cout << i << " ";
        cout << "]" << endl;
    }
    if (i == n)
        return;
    if (v[i] <= target_sum) {
        ans.push_back(v[i]);
        find_way(i + 1, target_sum - v[i], ans);
        ans.pop_back();
    }
    find_way(i + 1, target_sum, ans);
}

void solve() {
    cin >> n;
    v.resize(n);
    for (auto &i : v)
        cin >> i;
    cin >> sum;
    find_way(0, sum);
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
