#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, e;
    cin >> n >> e;
    vector<int> adj_list[n];   
    
    while (e--) {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
    }
    
    int q;
    cin >> q;
    
    while (q--) {
        int a, b;
        cin >> a >> b;
        
        if (a == b) {
            cout << "YES\n";
            continue;
        }
        
        bool found = false;
        for (int x : adj_list[a]) {
            if (x == b) {
                found = true;
                break;
            }
        }
        
        if (found) 
        {
            cout << "YES\n";
        } 
        else 
        {
            cout << "NO\n";
        }
    }
    
    return 0;
}