#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        long long X;
        cin >> N >> X;

        vector<long long> H(N);
        for (int i = 0; i < N; ++i) 
        {
            cin >> H[i];
        }

        sort(H.begin(), H.end());

        long long requiredAttack = 0;
        long long currentHP = 0;

        for (int i = N - 1; i >= 0; --i) 
        {
            currentHP = H[i] + (N - 1 - i) * X;
            requiredAttack = max(requiredAttack, currentHP);
        }

        cout << requiredAttack << endl;
    }

    return 0;
}
