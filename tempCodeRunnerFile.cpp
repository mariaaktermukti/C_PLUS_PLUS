#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;  // Read n and m (m is always 1)

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];  // Read array a

    int b;
    cin >> b;  // Read the only element of array b

    // Perform the operation: a[i] = b - a[i] (if necessary)
    for (int i = 0; i < n; i++) {
        a[i] = min(a[i], b - a[i]); // Ensure we get the smallest possible value
    }

    // Check if the modified array is sorted
    if (is_sorted(a.begin(), a.end())) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;  // Number of test cases

    while (t--) {
        solve();
    }

    return 0;
}
