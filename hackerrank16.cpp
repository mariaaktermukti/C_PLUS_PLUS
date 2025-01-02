#include<bits/stdc++.h>
using namespace std;

int main() {
    list<int> linkedList;
    list<int> uniqueList;  
    int value;

    while (cin >> value && value != -1)
    {
        linkedList.push_back(value);
    }

    for (int val : linkedList) 
    {
        if (find(uniqueList.begin(), uniqueList.end(), val) == uniqueList.end())
        {
            uniqueList.push_back(val); 
        }
    }

    uniqueList.sort();

    for (int val : uniqueList) 
    {
        cout << val << " ";
    }

    cout << endl;

    return 0;
}
