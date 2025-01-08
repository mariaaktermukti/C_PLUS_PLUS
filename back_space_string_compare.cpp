#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int i = s.length() - 1;
        int j = t.length() - 1; 

        while (i >= 0 || j >= 0) 
        {
            int skipS = 0, skipT = 0;

            while (i >= 0) 
            {
                if (s[i] == '#') 
                {
                    skipS++;
                    i--;
                } 
                else if (skipS > 0) 
                {
                    skipS--;
                    i--;
                } 
                else 
                {
                    break;
                }
            }

            while (j >= 0) 
            {
                if (t[j] == '#') 
                {
                    skipT++;
                    j--;
                } 
                else if (skipT > 0) 
                {
                    skipT--;
                    j--;
                } 
                else 
                {
                    break;
                }
            }

            if (i >= 0 && j >= 0 && s[i] != t[j]) 
            {
                return false;
            }

            if ((i >= 0) != (j >= 0)) 
            {
                return false;
            }

            i--;
            j--;
        }

        return true;
    }
};

int main() {
    Solution solution;

    string s1 = "ab#c", t1 = "ad#c";
    string s2 = "ab##", t2 = "c#d#";
    string s3 = "a#c", t3 = "b";

    cout << "Test 1: " << (solution.backspaceCompare(s1, t1) ? "true" : "false") << endl; 
    cout << "Test 2: " << (solution.backspaceCompare(s2, t2) ? "true" : "false") << endl;
    cout << "Test 3: " << (solution.backspaceCompare(s3, t3) ? "true" : "false") << endl;

    return 0;
}
