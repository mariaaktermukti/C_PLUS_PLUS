#include <iostream>
#include <stack>
using namespace std;
bool isValidString(const string& s) 
{
    stack<char> stk;
    for (char ch : s) 
    {
        if (ch == '1' && !stk.empty() && stk.top() == '0') 
        {
            stk.pop();
        } 
        else if (ch == '0' && !stk.empty() && stk.top() == '1') 
        {
            stk.pop();
        } 
        else 
        {
            stk.push(ch);
        }
    }
    return stk.empty();
}

int main() {
    int t;
    cin >> t;

    while (t--) 
    {
        string s;
        cin >> s;
        if (isValidString(s)) 
        {
            cout << "YES" << endl;
        } 
        else 
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}
