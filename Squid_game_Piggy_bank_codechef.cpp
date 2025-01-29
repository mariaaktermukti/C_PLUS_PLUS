#include <iostream>

using namespace std;

int main() {
    int N, K;
    
    cin >> N >> K;

    if (K >= N || N > 100 || K < 1) {
        cerr << "Invalid input: Ensure that 1 ≤ K < N ≤ 100" << endl;
        return 1; 
    }

    int eliminatedPlayers = N - K;
    int prizeMoney = eliminatedPlayers * 10000;

    cout << prizeMoney << endl;

    return 0;
}
