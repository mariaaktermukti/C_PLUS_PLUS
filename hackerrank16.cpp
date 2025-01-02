#include<bits/stdc++.h>
using namespace std;

int main() 
{
    list<int> linkedList;
    set<int> uniqueValues;
    int value;

    while (cin >> value && value != -1)
    {
        linkedList.push_back(value);
    }

    for (int val : linkedList)
    {
        uniqueValues.insert(val);
    }

    linkedList.clear();
    for (int val : uniqueValues) 
    {
        linkedList.push_back(val);
    }

    linkedList.sort();

    for (int val : linkedList)
    {
        cout << val << " ";
    }

    cout << endl;
    
    return 0;
}
