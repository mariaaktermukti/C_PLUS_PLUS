#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> diff(n + 1, 0);

        for (const auto& shift : shifts) {
            int start = shift[0];
            int end = shift[1];
            int direction = shift[2] == 1 ? 1 : -1;

            diff[start] += direction;
            diff[end + 1] -= direction;
        }

        int cumulativeShift = 0;
        for (int i = 0; i < n; ++i) {
            cumulativeShift += diff[i];
            int normalizedShift = (cumulativeShift % 26 + 26) % 26;
            s[i] = 'a' + (s[i] - 'a' + normalizedShift) % 26;
        }

        return s;
    }
};

int main() {
    Solution solution;

    string s1 = "abc";
    vector<vector<int>> shifts1 = {{0, 1, 0}, {1, 2, 1}, {0, 2, 1}};
    cout << "Example 1 Output: " << solution.shiftingLetters(s1, shifts1) << endl;

    string s2 = "dztz";
    vector<vector<int>> shifts2 = {{0, 0, 0}, {1, 1, 1}};
    cout << "Example 2 Output: " << solution.shiftingLetters(s2, shifts2) << endl;

    return 0;
}
