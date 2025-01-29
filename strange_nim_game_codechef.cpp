#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int MOD = 1000000007;
const int MAXN = 200005;
vector<int> segTree(4 * MAXN);  // Segment Tree for XOR
vector<int> A(MAXN);  // Original Array

// Function to compute (base^exp) % MOD
long long powerMod(long long base, long long exp) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % MOD;
        }
        base = (base * base) % MOD;
        exp /= 2;
    }
    return result;
}

// Function to build the segment tree
void build(int node, int start, int end) {
    if (start == end) {
        segTree[node] = A[start];
    } else {
        int mid = (start + end) / 2;
        build(2 * node, start, mid);
        build(2 * node + 1, mid + 1, end);
        segTree[node] = segTree[2 * node] ^ segTree[2 * node + 1];  // XOR operation
    }
}

// Function to update the segment tree
void update(int node, int start, int end, int idx, int val) {
    if (start == end) {
        A[start] = val;
        segTree[node] = val;
    } else {
        int mid = (start + end) / 2;
        if (idx <= mid) {
            update(2 * node, start, mid, idx, val);
        } else {
            update(2 * node + 1, mid + 1, end, idx, val);
        }
        segTree[node] = segTree[2 * node] ^ segTree[2 * node + 1];
    }
}

// Function to query the XOR for range [L, R]
int query(int node, int start, int end, int L, int R) {
    if (R < start || L > end) {
        return 0;  // Out of range
    }
    if (L <= start && end <= R) {
        return segTree[node];  // Completely inside range
    }
    int mid = (start + end) / 2;
    int leftXOR = query(2 * node, start, mid, L, R);
    int rightXOR = query(2 * node + 1, mid + 1, end, L, R);
    return leftXOR ^ rightXOR;
}

// Function to count winning subsequences
long long countWinningSubsequences(int L, int R) {
    int subarrayXOR = query(1, 1, MAXN, L, R);
    int numElements = (R - L + 1);

    long long totalSubsequences = (powerMod(2, numElements) - 1 + MOD) % MOD;
    long long zeroXORSubsequences = (subarrayXOR == 0) ? totalSubsequences : 0;

    return (totalSubsequences - zeroXORSubsequences + MOD) % MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;  // Number of towers

    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }

    build(1, 1, N);  // Build segment tree

    int Q;
    cin >> Q;  // Number of queries

    while (Q--) {
        int type;
        cin >> type;

        if (type == 1) {
            int L, R;
            cin >> L >> R;
            cout << countWinningSubsequences(L, R) << "\n";
        } else if (type == 2) {
            int i, x;
            cin >> i >> x;
            update(1, 1, N, i, x);
        }
    }

    return 0;
}
