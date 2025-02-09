#include <iostream>
#include <vector>
#define MOD 998244353
using namespace std;

// ✅ Fast Modular Exponentiation: Computes (base^exp) % mod
long long modExp(long long base, long long exp, long long mod) {
    long long res = 1;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return res;
}

// ✅ Solve each test case
void solve() {
    string s;
    int q;
    cin >> s >> q;
    
    int n = s.size();
    vector<int> queries(q);
    for (int i = 0; i < q; i++) {
        cin >> queries[i];
        queries[i]--;  // Convert to 0-based index
    }

    // ✅ Step 1: Compute Initial `f(s)`
    int f_count = 1;
    for (int i = 1; i < n; i++) {
        if (s[i] != s[i - 1]) {
            f_count++;
        }
    }

    // ✅ Step 2: Compute initial sum of `f(subsequences)`
    long long total_sum = modExp(2, f_count - 1, MOD);

    // ✅ Step 3: Process Each Query
    vector<long long> results;
    for (int flip : queries) {
        // Check boundary effects
        if (flip > 0 && s[flip] != s[flip - 1]) f_count--;
        if (flip < n - 1 && s[flip] != s[flip + 1]) f_count--;
        
        // Flip the bit
        s[flip] = (s[flip] == '0') ? '1' : '0';

        // Re-check boundary effects
        if (flip > 0 && s[flip] != s[flip - 1]) f_count++;
        if (flip < n - 1 && s[flip] != s[flip + 1]) f_count++;

        // ✅ Recalculate `f(subsequences)` sum
        total_sum = modExp(2, f_count - 1, MOD);
        results.push_back(total_sum);
    }

    // ✅ Print all results for the test case
    for (long long res : results) cout << res << " ";
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
