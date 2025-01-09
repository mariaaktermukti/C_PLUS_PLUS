#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int prefixCount(vector<string>& words, string pref) 
    {
        int count = 0; 
        for (const auto& word : words) 
        {
            if (word.find(pref) == 0) 
            {
                ++count; 
            }
        }
        return count; 
    }
};

int main() {
    Solution solution;

    vector<string> words1 = {"pay", "attention", "practice", "attend"};
    string pref1 = "at";
    cout << "Test Case 1: " << solution.prefixCount(words1, pref1) << endl; 

    vector<string> words2 = {"leetcode", "win", "loops", "success"};
    string pref2 = "code";
    cout << "Test Case 2: " << solution.prefixCount(words2, pref2) << endl; 

    return 0;
}
