#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string s;
    int k;

    cout << "Enter the string: ";
    cin >> s;
    cout << "Enter the value of k: ";
    cin >> k;

    if (k == 1) 
    {
        string result = s;
        string current = s;
        for (int i = 1; i < s.size(); ++i) 
        {
            current = current.substr(1) + current[0]; 
            if (current < result) 
            {
                result = current;
            }
        }
        cout << "Lexicographically smallest string: " << result << endl;
    } 
    else 
    {
        sort(s.begin(), s.end()); 
        cout << "Lexicographically smallest string: " << s << endl;
    }

    return 0;
}
