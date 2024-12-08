#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> v={1,2,3,4}; 
    // v.pop_back();
    // v.pop_back();
    // vector<int> v2;  
    // v2=v;  
    // for(int i=0;i<v2.size();i++)
    // {
    //     cout << v2[i] << " ";
    // }
    // for(int x :v)
    // {
    //     cout << x << " ";
    // }

     v.insert(v.begin()+2,100);
     for(int x :v)
    {
        cout << x << " ";
    }
    return 0; 

}

