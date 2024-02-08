#include <bits/stdc++.h>
using namespace std;

class Node {
   public:
    int value;
    int wt;
    Node(int wt, int value) {
        this->wt = wt;
        this->value = value;
    }
};

class Q {
   public:
    int idx, Ub, v, w;
    Q(int idx, int w, int v, int Ub) {
        this->idx = idx;
        this->w = w;
        this->v = v;
        this->Ub = Ub;
    }
};

bool cmp(Node a, Node b) {
    if (a.value / a.wt > b.value / b.wt)
        return true;
    return false;
}

int findUb(int v, int W, int w, int vnext, int wnext) {
    return v + (W - w) * (vnext / wnext);
}

int main() {
    int n, capacity;
    cin >> n >> capacity;
    vector<Node> v;
    for (int i = 0; i < n; i++) {
        int wt, value;
        cin >> wt >> value;
        v.push_back(Node(wt, value));
    }
    sort(v.begin(), v.end(), cmp);
    queue<Q> q;
    int Ub = findUb(0, capacity, 0, v[0].value, v[0].wt);
    q.push(Q(-1, 0, 0, Ub));
    int mx = 0;
    while (q.size()) {
        Q temp = q.front();
        q.pop();
        mx = max(mx, temp.v);
        int idx = temp.idx;
        if (idx + 2 > n)
            continue;
        int takeV = temp.v + v[idx + 1].value;
        int nottakeV = temp.v;
        int takeW = temp.w + v[idx + 1].wt;
        int nottakeW = temp.w;
        int takeUb = findUb(takeV, capacity, takeW, v[idx + 2].value, v[idx + 2].wt);
        int nottakeUb = findUb(nottakeV, capacity, nottakeW, v[idx + 2].value, v[idx + 2].wt);
        if (takeW <= capacity and mx < takeUb)
            q.push(Q(idx + 1, takeW, takeV, takeUb));
        if (mx < nottakeUb)
            q.push(Q(idx + 1, nottakeW, nottakeV, nottakeUb));
    }
    cout << mx << endl;
}
