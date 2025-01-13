#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int minimumLength(string s) {
        int left = 0, right = s.length() - 1;

        // Use two pointers to shrink the string from both ends
        while (left < right && s[left] == s[right]) {
            char currentChar = s[left];

            // Move the left pointer to skip characters matching the currentChar
            while (left <= right && s[left] == currentChar) {
                left++;
            }

            // Move the right pointer to skip characters matching the currentChar
            while (left <= right && s[right] == currentChar) {
                right--;
            }
        }

        // The remaining string length
        return right - left + 1;
    }
};

int main() {
    Solution solution;

    // Example 1
    string s1 = "abaacbcbb";
    cout << "Input: " << s1 << "\nOutput: " << solution.minimumLength(s1) << "\n\n";

    // Example 2
    string s2 = "aa";
    cout << "Input: " << s2 << "\nOutput: " << solution.minimumLength(s2) << "\n\n";

    // Additional Test Cases
    string s3 = "a";
    cout << "Input: " << s3 << "\nOutput: " << solution.minimumLength(s3) << "\n\n";

    string s4 = "abcddcba";
    cout << "Input: " << s4 << "\nOutput: " << solution.minimumLength(s4) << "\n\n";

    string s5 = "aabccbaa";
    cout << "Input: " << s5 << "\nOutput: " << solution.minimumLength(s5) << "\n\n";

    return 0;
}