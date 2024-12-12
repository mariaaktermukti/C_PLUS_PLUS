//duplicate
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n; 

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    for (int i = 1; i < n; i++) {
        if (arr[i] == arr[i - 1]) {
            cout << "YES" << endl; 
            return 0; 
        }
    }
    cout << "NO" << endl;
    return 0;
}
