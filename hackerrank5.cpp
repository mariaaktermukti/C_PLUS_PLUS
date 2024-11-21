#include <iostream>
#include <algorithm>
using namespace std;

bool find_triplet_sum(int A[], int N, int S) {
    sort(A, A + N);
    
    for (int i = 0; i < N - 2; i++) {
        int left = i + 1, right = N - 1;
        
        while (left < right) {
            int current_sum = A[i] + A[left] + A[right];
            
            if (current_sum == S) {
                return true; 
            }
            else if (current_sum < S) {
                left++;  
            }
            else {
                right--;  
            }
        }
    }
    
    return false;  
}

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        int N, S;
        cin >> N >> S;

        int A[100];
        
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        if (find_triplet_sum(A, N, S)) {
            cout << "YES" << endl;
        } 
        else {
            cout << "NO" << endl;
        }
    }
    
    return 0;
}
