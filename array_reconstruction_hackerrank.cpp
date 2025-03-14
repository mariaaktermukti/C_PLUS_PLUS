#include <iostream>
using namespace std;

int main() 
{
    int t;
    cin >> t;
    
    while (t--) 
    {
        int n;
        cin >> n;
        
        long long sum = 0;
        
        for (int i = 0; i < n - 2; i++) 
        {
            long long temp;
            cin >> temp;
            sum = sum + temp;
        }
        
        long long sum_original;
        cin >> sum_original;
        
        long long sum_deleted = sum_original - sum;
        
        if (sum_deleted >= 0) 
        {
            cout << sum_deleted + 1 << endl;
        } 
        else 
        {
            cout << 0 << endl;
        }
    }
    
    return 0;
}
