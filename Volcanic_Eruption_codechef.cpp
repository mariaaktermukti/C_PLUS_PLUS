#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void solve() {
    int N, P;
    cin >> N >> P;

    vector<int> A(N);
    vector<int> time(N, INT_MAX); // Store earliest time when submerged

    // Read input
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        if (A[i] == 0) time[i] = 0; // Volcanoes get time 0
    }

    // Left-to-Right Simulation
    int lavaLevel = 0, currTime = 0;
    for (int i = 0; i < N; i++) {
        if (A[i] == 0) { // Volcano resets lava level
            lavaLevel = 0;
            currTime = 0;
        } else {
            currTime++;
            lavaLevel += P;

            if (A[i] <= lavaLevel) { // If building is submerged
                time[i] = min(time[i], currTime);
            } else {
                lavaLevel = 0; // Stop lava if blocked
            }
        }
    }

    // Right-to-Left Simulation
    lavaLevel = 0, currTime = 0;
    for (int i = N - 1; i >= 0; i--) {
        if (A[i] == 0) { // Volcano resets lava level
            lavaLevel = 0;
            currTime = 0;
        } else {
            currTime++;
            lavaLevel += P;

            if (A[i] <= lavaLevel) { // If building is submerged
                time[i] = min(time[i], currTime);
            } else {
                lavaLevel = 0; // Stop lava if blocked
            }
        }
    }

    // Print final results
    for (int i = 0; i < N; i++) {
        cout << time[i] << " ";
    }
    cout << endl;
}

int main() {
    int T;
    cin >> T; // Read number of test cases

    while (T--) {
        solve();
    }

    return 0;
}
