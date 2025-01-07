#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) 
    {
        if (s.empty()) return "";

        int start = 0, maxLength = 1; 

        for (int i = 0; i < s.size(); ++i) 
        {
            expandAroundCenter(s, i, i, start, maxLength);

            expandAroundCenter(s, i, i + 1, start, maxLength);
        }

        return s.substr(start, maxLength);
    }

private:
    void expandAroundCenter(const string& s, int left, int right, int& start, int& maxLength) 
    {
        while (left >= 0 && right < s.size() && s[left] == s[right]) 
        {
            int currentLength = right - left + 1;
            if (currentLength > maxLength) 
            {
                maxLength = currentLength;
                start = left;
            }
            --left;
            ++right;
        }
    }
};

int main() {
    Solution solution;

    string s1 = "babad";
    cout << "Longest palindrome in \"" << s1 << "\": " << solution.longestPalindrome(s1) << endl;

    string s2 = "cbbd";
    cout << "Longest palindrome in \"" << s2 << "\": " << solution.longestPalindrome(s2) << endl;

    string s3 = "a";
    cout << "Longest palindrome in \"" << s3 << "\": " << solution.longestPalindrome(s3) << endl;

    string s4 = "ac";
    cout << "Longest palindrome in \"" << s4 << "\": " << solution.longestPalindrome(s4) << endl;

    return 0;
}
