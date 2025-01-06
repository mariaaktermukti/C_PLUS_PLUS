#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> charSet; 
        int left = 0, maxLength = 0;

        for (int right = 0; right < s.length(); ++right) {
            while (charSet.find(s[right]) != charSet.end()) {
                charSet.erase(s[left]);
                ++left;
            }
            charSet.insert(s[right]);
            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};

int main() {
    Solution solution;

    string s1 = "abcabcbb";
    cout << "Input: " << s1 << endl;
    cout << "Output: " << solution.lengthOfLongestSubstring(s1) << endl;

    string s2 = "bbbbb";
    cout << "Input: " << s2 << endl;
    cout << "Output: " << solution.lengthOfLongestSubstring(s2) << endl;

    string s3 = "pwwkew";
    cout << "Input: " << s3 << endl;
    cout << "Output: " << solution.lengthOfLongestSubstring(s3) << endl;

    string s4 = " ";
    cout << "Input: " << s4 << endl;
    cout << "Output: " << solution.lengthOfLongestSubstring(s4) << endl;

    return 0;
}
