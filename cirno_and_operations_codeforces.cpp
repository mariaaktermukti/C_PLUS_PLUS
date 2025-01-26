#include <iostream>
#include <vector>
#include <algorithm>

void solve() {
    int t;
    std::cin >> t; // Number of test cases

    while (t--) {
        int n;
        std::cin >> n; // Length of the sequence
        std::vector<int> a(n);

        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
        }

        // Find the maximum and minimum elements in the sequence
        int max_val = *std::max_element(a.begin(), a.end());
        int min_val = *std::min_element(a.begin(), a.end());

        // The maximum possible sum after operations
        int max_sum = max_val - min_val;

        std::cout << max_sum << std::endl;
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
    return 0;
}
