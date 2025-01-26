#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void solve() {
    int t;
    cin >> t; // Number of test cases

    while (t--) {
        int n;
        cin >> n; // Number of nodes
        vector<int> l(n);
        vector<int> r(n);
        vector<vector<int>> tree(n);

        for (int i = 0; i < n; ++i) {
            cin >> l[i] >> r[i];
        }

        for (int i = 0; i < n - 1; ++i) {
            int u, v;
            cin >> u >> v;
            --u; --v;
            tree[u].push_back(v);
            tree[v].push_back(u);
        }

        // BFS to find the minimum value
        vector<int> min_value(n, INT_MAX);
        queue<int> q;
        q.push(0);
        min_value[0] = l[0];

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : tree[u]) {
                if (min_value[v] > min(min_value[u], l[v])) {
                    min_value[v] = min(min_value[u], l[v]);
                    q.push(v);
                }
            }
        }

        int result = *max_element(min_value.begin(), min_value.end());
        cout << result << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
