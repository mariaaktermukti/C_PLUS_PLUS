#include <iostream>
using namespace std;

int getChocolates(int N) 
{
    if (N < 5) {
        return 0;  
    }
    
    int chocolates = N / 5;
    
    int remainingMoney = N % 5;
    
    int wrappers = chocolates;
    
    while (wrappers >= 3) 
    {
        int newChocolates = wrappers / 3;
        wrappers = wrappers % 3 + newChocolates;
        chocolates += newChocolates;
    }
    
    return chocolates;
}

int main() 
{
    int T;
    cin >> T;
    
    while (T--) 
    {
        int N;
        cin >> N;
        cout << getChocolates(N) << endl;
    }
    
    return 0;
}
