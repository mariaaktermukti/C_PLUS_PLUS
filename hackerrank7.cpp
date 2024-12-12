#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

int main() {
    int n;
    cin >> n; 

    vector<int> a(n);   
    vector<int> prefix(n); 

    for (int i = 0; i < n; i++) {
        cin >> a[i]; 
    }
    prefix[0] = a[0];
    for (int i = 1; i < n; i++) {
        prefix[i] = prefix[i - 1] + a[i];
    }
    reverse(prefix.begin(), prefix.end());

    for (int i = 0; i < n; i++) {
        cout << prefix[i] << " ";
    }
    cout << endl;

    return 0;
}
