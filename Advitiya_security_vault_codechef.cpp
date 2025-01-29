#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1000000007;

// Fast modular exponentiation: (base^exp) % MOD
long long powerMod(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

// Function to calculate the minimum attempts Toofan must make
long long countAttempts(int N, int K, vector<int>& A) {
    int unknownCount = 0;

    // Count the number of unknown positions (`0`s in A)
    for (int i = 0; i < N; i++) {
        if (A[i] == 0) unknownCount++;
    }

    // Unique tries considering the reverse sequences
    int effectiveUnknowns = (unknownCount + 1) / 2;

    // Compute K^effectiveUnknowns % MOD using fast exponentiation
    return powerMod(K, effectiveUnknowns, MOD);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T; // Number of test cases

    while (T--) {
        int N, K;
        cin >> N >> K; // Length of passcode and range of digits

        vector<int> A(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i]; // Read passcode information
        }

        cout << countAttempts(N, K, A) << "\n"; // Compute answer
    }

    return 0;
}
