#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    int T;
    cin >> T; 

    while (T--) {
        string S;
        cin >> S; 

        stack<char> stk;
        for (char ch : S) 
        {
            if (!stk.empty() && stk.top() == '0' && ch == '1') 
            {
                stk.pop(); 
            } 
            else 
            {
                stk.push(ch);
            }
        }

        if (stk.empty()) 
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