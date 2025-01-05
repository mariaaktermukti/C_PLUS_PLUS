#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> cars(n);
    for (int i = 0; i < n; ++i) {
        cin >> cars[i];
    }

    vector<pair<int, int>> overtakes;

    // Simulate all possible overtakes
    for (int i = 0; i < n; ++i) {
        for (int j = n - 1; j > i; --j) {
            if (cars[j] < cars[j - 1]) {
                overtakes.push_back({cars[j - 1], cars[j]});
                swap(cars[j], cars[j - 1]);
            }
        }
    }

    // Add reverse overtakes for maximum sequence
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (cars[i] > cars[j]) {
                overtakes.push_back({cars[i], cars[j]});
                swap(cars[i], cars[j]);
            }
        }
    }

    // Output the results
    cout << overtakes.size() << endl;
    for (const auto& overtake : overtakes) {
        cout << overtake.first << " " << overtake.second << endl;
    }

    return 0;
}
