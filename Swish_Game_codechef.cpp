#include <iostream>
#include <string>

using namespace std;

int findTotalRings(int M, int K, string S) {
    int currentSwishes = 0;

    for (char move : S) 
    {
        if (move == 'S') 
        {
            currentSwishes++;
        }
    }

    if (currentSwishes >= K) 
    {
        return M;
    }

    return M + (K - currentSwishes) - 1;
}

int main() 
{
    int T;
    cin >> T; 

    while (T--) 
    {
        int M, K;
        string S;
        cin >> M >> K; 
        cin >> S; 

        cout << findTotalRings(M, K, S) << endl; 
    }

    return 0;
}
