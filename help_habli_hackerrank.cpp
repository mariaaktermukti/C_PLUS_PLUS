#include <iostream>
#include <string>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        string s, t;
        cin >> s >> t; 
        
        long long count1 = 0, count2 = 0, count3 = 0;
        
        for (char c : s) 
        {
            if (c == t[2]) 
            {
                count3 += count2; 
            }
            if (c == t[1]) 
            {
                count2 += count1; 
            }
            if (c == t[0]) 
            {
                count1++;         
            }
        }
        
        cout << count3 << "\n";
    }
    return 0;
}
