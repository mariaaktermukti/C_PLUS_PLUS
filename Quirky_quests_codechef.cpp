#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

// Function to compute the MEX of a vector
int calculateMEX(const vector<int>& arr) {
    unordered_set<int> present;
    for (int num : arr) {
        present.insert(num);
    }

    int mex = 0;
    while (present.find(mex) != present.end()) {
        ++mex;
    }
    return mex;
}

// Function to compute the maximum possible sum f(A)
long long computeMaxSum(vector<int>& arr) {
    long long sum = 0;
    for (int num : arr) {
        sum += num;
    }

    int mex = calculateMEX(arr);

    // Calculate maximum possible sum by replacing all elements with MEX
    long long maxPossibleSum = static_cast<long long>(mex) * arr.size();

    return max(maxPossibleSum, sum);
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;
        vector<int> A(N);

        for (int i = 0; i < N; ++i) {
            cin >> A[i];
        }

        cout << computeMaxSum(A) << "\n";
    }

    return 0;
}
