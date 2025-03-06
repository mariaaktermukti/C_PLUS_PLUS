#include <iostream>
using namespace std;

bool canReach(int N) {
    while (N > 1) {
        if (N % 2 == 0) {
            N /= 2;  
        } else {
            N -= 3; 
        }
    }
    return (N == 1);
}

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        int N;
        cin >> N;
        cout << (canReach(N) ? "YES" : "NO") << "\n";
    }
    
    return 0;
}