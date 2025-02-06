//connected nodes
#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int n, e;
    cin >> n >> e;
    vector<int> adj_list[n];     
    
    while (e--) 
    {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a); 
    }
    
    int q;
    cin >> q;
    
    while (q--) 
    {
        int a;
        cin >> a;
        
        if (adj_list[a].empty()) 
        {
            cout << "-1\n";
        }
        else 
        {
            sort(adj_list[a].rbegin(), adj_list[a].rend());
            for (int x : adj_list[a]) 
            {
                cout << x << " ";
            }
            cout << "\n";
        }
    }
    
    return 0;
}
