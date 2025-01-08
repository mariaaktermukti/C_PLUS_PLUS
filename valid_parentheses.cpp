#include <iostream>
#include <stack>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char, char> matching = {
            {')', '('},
            {'}', '{'},
            {']', '['}
        };
        
        for (char c : s) 
        {
            if (matching.count(c)) 
            {
                if (!st.empty() && st.top() == matching[c]) 
                {
                    st.pop(); 
                } 
                else 
                {
                    return false; 
                }
            } 
            else 
            {
                st.push(c);
            }
        }
        return st.empty();
    }
};

int main() {
    Solution solution;
    string test1 = "()";
    string test2 = "()[]{}";
    string test3 = "(]";
    string test4 = "([])";
    
    cout << "Test 1: " << (solution.isValid(test1) ? "true" : "false") << endl;
    cout << "Test 2: " << (solution.isValid(test2) ? "true" : "false") << endl;
    cout << "Test 3: " << (solution.isValid(test3) ? "false" : "true") << endl;
    cout << "Test 4: " << (solution.isValid(test4) ? "true" : "false") << endl;
    
    return 0;
}
