#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

void solve() {
    int t;
    cin >> t; // Number of test cases

    while (t--) {
        int n;
        cin >> n; // Length of permutations
        vector<int> p(n);
        vector<int> q(n);
        vector<int> pos_p(n + 1);
        vector<int> pos_q(n + 1);
        vector<pair<int, int>> operations;

        for (int i = 0; i < n; ++i) {
            cin >> p[i];
            pos_p[p[i]] = i;
        }

        for (int i = 0; i < n; ++i) {
            cin >> q[i];
            pos_q[q[i]] = i;
        }

        // Calculate the cost of swapping elements to match the target permutation
        for (int i = 1; i <= n; ++i) {
            if (pos_p[i] != pos_q[i]) {
                int j = p[pos_q[i]];
                operations.push_back({pos_p[i] + 1, pos_p[j] + 1});
                swap(pos_p[i], pos_p[j]);
            }
        }

        // Output the number of operations
        cout << operations.size() << endl;

        // Output the operations
        for (const auto& op : operations) {
            cout << op.first << " " << op.second << endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
