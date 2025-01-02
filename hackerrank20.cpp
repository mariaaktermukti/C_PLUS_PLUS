#include <iostream>
#include <list>
using namespace std;

int main() {
    int Q;
    cin >> Q;
    
    list<int> dll; 
    
    for (int i = 0; i < Q; ++i) 
    {
        int X, V;
        cin >> X >> V;
        
        if (X == 0) 
        {
            dll.push_front(V);
        } 
        else if (X == 1) 
        {
            dll.push_back(V);
        } 
        else if (X == 2) 
        {
            if (V >= 0 && V < dll.size()) 
            {
                auto it = dll.begin();
                advance(it, V);
                dll.erase(it);
            }
        }
        
        cout << "L -> ";
        for (auto it = dll.begin(); it != dll.end(); ++it) 
        {
            cout << *it;
            if (next(it) != dll.end()) cout << " ";
        }
        cout << endl;

        cout << "R -> ";
        for (auto it = dll.rbegin(); it != dll.rend(); ++it) 
        {
            cout << *it;
            if (next(it) != dll.rend()) cout << " ";
        }
        cout << endl;
    }
    
    return 0;
}
