#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, M, X; 

    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    cin >> M;
    vector<int> B(M);
    for (int i = 0; i < M; i++) {
        cin >> B[i];
    }

    cin >> X;

    A.insert(A.begin() + X, B.begin(), B.end());

    for (int i = 0; i < A.size(); i++) {
        cout << A[i] << " ";
    }
    cout << endl;

    return 0;
}
