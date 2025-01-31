#include <iostream>
#include <vector>

using namespace std;

vector<long long> computePrefixSum(const vector<int>& arr) 
{
    int n = arr.size();
    vector<long long> prefixSum(n + 1, 0);
    
    for (int i = 1; i <= n; ++i) 
    {
        prefixSum[i] = prefixSum[i - 1] + arr[i - 1];
    }
    
    return prefixSum;
}

int main() 
{
    int N, Q;
    cin >> N >> Q;
    
    vector<int> arr(N);
    for (int i = 0; i < N; ++i) 
    {
        cin >> arr[i];
    }
    
    int K;
    cin >> K;
    
    K = K % N;
    
    vector<int> rotatedArr(N);
    for (int i = 0; i < N; ++i) 
    {
        rotatedArr[(i + K) % N] = arr[i];
    }
    
    vector<long long> prefixSum = computePrefixSum(rotatedArr);

    while (Q--) 
    {
        int L, R;
        cin >> L >> R;
        
        cout << prefixSum[R] - prefixSum[L - 1] << endl;
    }
    
    return 0;
}
