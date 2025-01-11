#include <iostream>
#include <vector>
using namespace std;

long long maxSubarraySum(vector<int> arr, int n) 
{
    long long max_sum = 0; 
    long long current_sum = 0; 

    for (int i = 0; i < n; i++) 
    {
        current_sum += arr[i]; 
        if (current_sum < 0) 
        {
            current_sum = 0; 
        }
        max_sum = max(max_sum, current_sum);
    }

    return max_sum; 
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) 
    {
        cin >> arr[i];
    }

    long long result = maxSubarraySum(arr, n);

    cout << "The maximum subarray sum is: " << result << endl;

    return 0;
}
