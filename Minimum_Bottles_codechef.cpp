#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() 
{
    int T;
    cin >> T;

    while (T--) 
    {
        int N, X;
        cin >> N >> X;

        vector<int> A(N);
        for (int i = 0; i < N; ++i) 
        {
            cin >> A[i];
        }

        int totalWater = 0;
        for (int liters : A) 
        {
            totalWater += liters;
        }
        int minBottles = (totalWater + X - 1) / X; 

        cout << minBottles << endl;
    }

    return 0;
}
