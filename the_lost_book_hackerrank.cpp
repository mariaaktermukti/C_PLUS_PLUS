#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> books(n);
    for (int i = 0; i < n; i++) 
    {
        cin >> books[i];
    }
    
    int target;
    cin >> target;
    
    for (int i = 0; i < n; i++) 
    {
        if (books[i] == target) 
        {
            cout << i;
            return 0;
        }
    }
    
    cout << -1;
    return 0;
}
