#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> A(N);
    
    for (int i = 0; i < N; ++i) 
    {
        cin >> A[i];
    }
    
    vector<long long> prefixSum(N);
    prefixSum[0] = A[0];
    for (int i = 1; i < N; ++i) 
    {
        prefixSum[i] = prefixSum[i - 1] + A[i];
    }
    
    int Q;
    cin >> Q;
    
    while (Q--)
    {
        long long S;
        cin >> S;

        int low = 0, high = N - 1, ans = -1;
        
        while (low <= high) 
        {
            int mid = (low + high) / 2;
            if (prefixSum[mid] >= S) 
            {
                ans = mid + 1;  
                high = mid - 1;
            } 
            else 
            {
                low = mid + 1;
            }
        }
        
        cout << ans << '\n';
    }
    
    return 0;
}
