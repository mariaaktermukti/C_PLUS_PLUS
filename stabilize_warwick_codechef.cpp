#include <iostream>
#include <vector>
using namespace std;

void solve() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        vector<int> P(N);
        for (int i = 0; i < N; ++i) {
            cin >> P[i];
        }

        vector<pair<int, int>> operations;

        // Choose the last pump as the reference pump
        int refPump = N;

        // Ensure all even-indexed pumps match the reference pump
        for (int i = 1; i < N; i += 2) {
            operations.push_back({i + 1, refPump});
        }

        // Ensure all odd-indexed pumps match the reference pump
        for (int i = 0; i < N; i += 2) {
            operations.push_back({i + 1, refPump});
        }

        // Output results
        cout << operations.size() << "\n";
        for (const auto &op : operations) {
            cout << op.first << " " << op.second << "\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
