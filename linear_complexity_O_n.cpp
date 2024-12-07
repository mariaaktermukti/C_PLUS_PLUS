#include <iostream>
using namespace std;
int main()
{
    int n;  // complexity --> O(1)
    cin>> n; // O(1)
    for(int i=1;i<=n;i++) // O(n)
    {
        cout << i << " ";
    }
    return 0; //O(1)

}

// so, final complexity--> O(n) 