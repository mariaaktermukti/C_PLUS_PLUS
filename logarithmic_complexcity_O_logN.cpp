#include <iostream>
using namespace std;
int main()
{
    int n; 
    cin>> n; 
    // for(int i=1;i<=n;i*=2) //complexicty --> O(logN)
    // {
    //     cout << i << endl;
    // }
    //  for(int i=n;i>=1;i/=3) //complexicty --> O(logN)
    // {
    //     cout << i << endl;
    // }
    int k=2;
      for(int i=1;i<n;i++) //complexicty --> O(log k base N)
    {
        cout << i << endl;
        i=i*k;
    }
    return 0; 

}

