#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool canSort(const vector<int>& a, int b) {
    int n = a.size();
    vector<int> transformed(n);

    for (int i = 0; i < n; ++i) {
        transformed[i] = b - a[i];
    }

    vector<int> original = a;
    sort(original.begin(), original.end());
    sort(transformed.begin(), transformed.end());

    for (int i = 0; i < n; ++i) {
        if (original[i] <= transformed[i]) {
            return true;
        }
    }

    return false;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        vector<int> b(m);

        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        for (int i = 0; i < m; ++i) {
            cin >> b[i];
        }

        if (canSort(a, b[0])) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
