#include <iostream>
#include <vector>
using namespace std;

int findEquilibriumIndex(const vector<int>& arr) {
    int n = arr.size();
    int totalSum = 0, leftSum = 0;

    for (int num : arr) {
        totalSum += num;
    }

    for (int i = 0; i < n; i++) {
        int rightSum = totalSum - leftSum - arr[i];
        
        if (leftSum == rightSum) {
            return i; 
        }
        
        leftSum += arr[i];
    }

    return -1; 
}

int main() {
    int n;
    cin >> n; 

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int result = findEquilibriumIndex(arr);
    cout << result << endl; 

    return 0;
}
