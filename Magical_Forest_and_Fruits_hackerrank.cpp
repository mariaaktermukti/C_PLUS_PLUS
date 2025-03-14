#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;
    
    vector<long long> fruits(N);
    for (int i = 0; i < N; i++) 
    {
        cin >> fruits[i];
    }
    
    vector<long long> prefix(N);
    prefix[0] = fruits[0];
    for (int i = 1; i < N; i++) 
    {
        prefix[i] = prefix[i - 1] + fruits[i];
    }
    
    for (int i = 0; i < Q; i++) 
    {
        int L, R;
        cin >> L >> R;
        L--;  
        R--;  
        if (L == 0)
            cout << prefix[R] << "\n";
        else
            cout << prefix[R] - prefix[L - 1] << "\n";
    }
    
    return 0;
}
