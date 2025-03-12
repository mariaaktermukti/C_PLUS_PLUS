#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;

bool isSelectedCoin(int mask, int i) 
{
    int value = mask;
    for (int j=0; j<i; j++) 
    {
        value = value/2;
    }
    return (value % 2 == 1);
}

int main() 
{
    int T;
    cin >> T;
    
    while(T--) 
    {
        int N;
        cin >> N;
        vector<int> coins(N);
        int total = 0;
        for (int i=0; i<N; i++) 
        {
            cin >> coins[i];
            total = total + coins[i];
        }
        
        int valSize1, valSize2 = -1;
        if (N % 2 == 0) 
        {
            valSize1 = N / 2;
        } 
        else 
        {
            valSize1 = (N + 1)/2; 
            valSize2 = N/2;       
        }
        
        int ans = INT_MAX;
        int totalSubsets = pow(2, N);  

        for (int mask=0; mask<totalSubsets; mask++) 
        {
            int count = 0;
            for (int i=0; i<N; i++) 
            {
                if (isSelectedCoin(mask, i)) 
                {
                    count++;
                }
            }
            
            if (count == valSize1 || (valSize2 != -1 && count == valSize2)) 
            {
                int sumSubset = 0;
                for (int i=0; i<N; i++) 
                {
                    if (isSelectedCoin(mask, i)) 
                    { 
                        sumSubset += coins[i];
                    }
                }
                int diff = abs(total - 2 * sumSubset);
                if (diff < ans)
                    ans = diff;
            }
        }
        
        cout << ans << "\n";
    }
    
    return 0;
}
