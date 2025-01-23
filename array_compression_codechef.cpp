#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

void solve() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;
        vector<int> A(N);
        unordered_map<int, int> frequency;

        // Read the array and count frequencies
        for (int i = 0; i < N; ++i) {
            cin >> A[i];
            frequency[A[i]]++;
        }

        // Prepare frequencies for compression
        vector<int> freqValues;
        for (const auto& entry : frequency) {
            freqValues.push_back(entry.second);
        }

        // Sort frequencies in descending order
        sort(freqValues.rbegin(), freqValues.rend());

        // Calculate the minimum compressed length
        int remaining = N;
        for (int freq : freqValues) {
            if (freq >= 2) {
                int pairs = freq / 2;
                remaining -= pairs * 2;
            }
        }

        cout << remaining << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
