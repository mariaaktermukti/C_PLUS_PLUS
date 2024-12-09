#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> v={1,2,3,2,5,2}; 
    // vector<int> v2={100,200,300};
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

    //  v.insert(v.begin()+2,v2.begin(),v2.end()); // multiple value insert

    // v.erase(v.begin()+1,v.begin()+5);
    // replace(v.begin(), v.end(),2,100);
     //  for(int x :v)
    // {
    //     cout << x << " ";
    // }

    auto it = find(v.begin(), v.end(), 5);
    // cout << *it << endl;
    if(it==v.end())
    {
        cout << "Not found";
    }
    else
    {
        cout << "found";
    }

   
    return 0; 

}

