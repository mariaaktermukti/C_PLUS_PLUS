#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);

int main() {
    fastio;
    int T;
    cin >> T;
    while(T--) {
        long long N, M;
        cin >> N >> M;

        if (N == M) {
            cout << -1 << "\n";
            continue;
        }

        vector<long long> seq;
        seq.push_back(N);

        for (int b = 0; b < 60; b++) {
            if (((N >> b) & 1LL) == 0LL) {
                long long candidate = N | (1LL << b);
                if (candidate <= M) {
                    seq.push_back(candidate);
                }
            }
        }

        if ((int)seq.size() < 2) {
            cout << -1 << "\n";
        } else {
            sort(seq.begin(), seq.end(), greater<long long>());

            cout << seq.size() << "\n";
            for (auto &val : seq) {
                cout << val << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}
