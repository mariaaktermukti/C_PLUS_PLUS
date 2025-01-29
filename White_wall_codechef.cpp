#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int minOperationsToWhiteWall(int N, string S) {
    vector<int> freq(3, 0);
    for (char c : S) {
        if (c == 'R') freq[0]++;
        else if (c == 'G') freq[1]++;
        else if (c == 'B') freq[2]++;
    }

    int minOperations = N;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 3; ++k) {
                if (i != j && j != k && i != k) {
                    int operations = 0;
                    for (int l = 0; l < N; ++l) {
                        char target = (l % 3 == 0) ? 'R' : (l % 3 == 1) ? 'G' : 'B';
                        if (S[l] != target) operations++;
                    }
                    minOperations = min(minOperations, operations);
                }
            }
        }
    }

    return minOperations;
}

int main() {
    int T;
    cin >> T;

    vector<int> results;

    while (T--) {
        int N;
        string S;
        cin >> N >> S;
        results.push_back(minOperationsToWhiteWall(N, S));
    }

    for (int result : results) {
        cout << result << endl;
    }

    return 0;
}
