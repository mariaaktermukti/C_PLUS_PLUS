//duplicate
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N; 

    vector<int> Arr(N);
    for (int i = 0; i < N; i++) {
        cin >> Arr[i];
    }
    sort(Arr.begin(), Arr.end());
    for (int i = 1; i < N; i++) {
        if (Arr[i] == Arr[i - 1]) {
            cout << "YES" << endl; 
            return 0; 
        }
    }
    cout << "NO" << endl;
    return 0;
}
