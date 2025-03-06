#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    long long tetranacci(int n) {
        if (n == 0) return 0;
        if (n == 1 || n == 2) return 1;
        if (n == 3) return 2;

        vector<long long> dp(n + 1);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 1;
        dp[3] = 2;

        for (int i = 4; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3] + dp[i - 4];
        }

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
