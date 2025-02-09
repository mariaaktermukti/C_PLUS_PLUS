#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

const int MAX_N = 200000;
vector<bool> isPrime(MAX_N + 1, true);
vector<bool> isSemiPrime(MAX_N + 1, false);

void precompute() {
    vector<int> primes;
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i <= MAX_N; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
            for (int j = 2 * i; j <= MAX_N; j += i) {
                isPrime[j] = false;
            }
        }
    }

    for (int i = 0; i < primes.size(); i++) {
        for (int j = i; j < primes.size(); j++) {
            long long semiPrime = 1LL * primes[i] * primes[j];
            if (semiPrime > MAX_N) break;
            isSemiPrime[semiPrime] = true;
        }
    }
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, int> freq;  

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        freq[a[i]]++;
    }

    vector<int> uniqueVals;
    for (auto p : freq) uniqueVals.push_back(p.first);

    long long result = 0;


    for (int i = 0; i < uniqueVals.size(); i++) {
        for (int j = i; j < uniqueVals.size(); j++) {
            int x = uniqueVals[i];
            int y = uniqueVals[j];

            long long lcmVal = (1LL * x * y) / __gcd(x, y);
            if (lcmVal > MAX_N) continue;

            if (isSemiPrime[lcmVal]) {
                if (x == y) {
                    result += 1LL * freq[x] * (freq[x] + 1) / 2;
                } else {
                    result += 1LL * freq[x] * freq[y];
                }
            }
        }
    }

    cout << result << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    precompute();  

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
