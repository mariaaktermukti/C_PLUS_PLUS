#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int t;
    cin >> t; // Number of test cases

    while (t--) {
        int n;
        cin >> n; // Number of clocks
        vector<long long> clocks(n);
        long long total_sum = 0, max_clock = 0;

        for (int i = 0; i < n; ++i) {
            cin >> clocks[i];
            total_sum += clocks[i];
            max_clock = max(max_clock, clocks[i]);
        }

        // Check the condition
        if (total_sum >= 2 * max_clock) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
