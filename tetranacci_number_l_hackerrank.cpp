#include <iostream>
#include <cstring>
using namespace std;

class Solution {
public:
    int dp[50];

    Solution() { 
        memset(dp, -1, sizeof(dp));
    }

    int tetranacci(int n) {
        if(n == 0) return 0;
        if(n == 1 || n == 2) return 1;
        if(n == 3) return 2;

        if(dp[n] != -1) return dp[n];

        dp[n] = tetranacci(n - 1) + tetranacci(n - 2) + tetranacci(n - 3) + tetranacci(n - 4);
        return dp[n];
    }
};

int main() {
    int n;
    cin >> n;  

    Solution sol;
    cout << sol.tetranacci(n) << endl; 

    return 0;
}
