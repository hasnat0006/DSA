#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, pair<string, int>>> v(n);
    for (int i = 0; i < n; i++) {
        int deadline, profit;
        string id;
        cin >> id >> deadline >> profit;
        v[i] = {profit, {id, deadline}};
        // insert profit first beacuse we need to sort according to profit.
    }
    vector<int> slot(n, -1);
    vector<string> chosen_job;
    int max_profit = 0;
    sort(v.rbegin(), v.rend());
    for (int i = 0; i < n; i++) {
        int dealline = v[i].second.second;
        for (int j = dealline - 1; j >= 0; j--) {
            if (slot[j] == -1) {
                slot[j] = i;
                max_profit += v[i].first;
                chosen_job.push_back(v[i].second.first);
                break;
            }
        }
    }
    cout << "Max profit: " << max_profit << endl;
    cout << "Job sequence: ";
    for (auto i : chosen_job)
        cout << i << " ";
    cout << endl;
}

/*
input: 

job id -> deadline >> profit
5
a 2 100
b 1 19
c 2 27
d 1 25
e 3 15

output: 
Max profit: 142
Job sequence: a c e

*/
