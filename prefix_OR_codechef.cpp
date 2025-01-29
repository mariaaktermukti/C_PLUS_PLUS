#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

int maxDistinctPrefixORs(vector<int>& A) {
    // Sort the array in descending order
    sort(A.begin(), A.end(), greater<int>());

    unordered_set<int> distinctORs;
    int currentOR = 0;

    // Calculate the prefix ORs
    for (int num : A) {
        currentOR |= num;
        distinctORs.insert(currentOR);
    }

    // The number of distinct prefix ORs
    return distinctORs.size();
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

        cout << maxDistinctPrefixORs(A) << endl;
    }

    return 0;
}
