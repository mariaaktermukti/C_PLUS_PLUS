#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std; 

int main() 
{
    int n;
    cin >> n;
    vector<int> list(n);
    for (int i = 0; i < n; ++i) 
    {
        cin >> list[i];
    }

    int q;
    cin >> q;
    multiset<int> minSet(list.begin(), list.end());

    for (int i = 0; i < q; ++i) 
    {
        int command;
        cin >> command;

        if (command == 1) 
        {
            if (!minSet.empty()) 
            {
                cout << *minSet.begin() << endl; 
            } 
            else 
            {
                cout << "Empty" << endl;
            }
        } 
        else if (command == 2) 
        {
            if (!minSet.empty()) 
            {
                minSet.erase(minSet.begin()); 
                if (!minSet.empty()) 
                {
                    cout << *minSet.begin() << endl;
                } 
                else 
                {
                    cout << "Empty" << endl;
                }
            } 
            else 
            {
                cout << "Empty" << endl;
            }
        } 
        else if (command == 0) 
        {
            int value;
            cin >> value;
            minSet.insert(value); 
            cout << *minSet.begin() << endl;
        }
    }

    return 0;
}
