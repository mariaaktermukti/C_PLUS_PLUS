#include <iostream>
#include <stack>

using namespace std;

int main() {
    int Q;
    cin >> Q;

    stack<int> machine;

    while (Q--) 
    {
        int command;
        cin >> command;

        if (command == 1) 
        {
            int sum = 0;
            stack<int> temp = machine; 
            while (!temp.empty()) 
            {
                sum += temp.top();
                temp.pop();
            }
            cout << sum << endl;
        } 
        else if (command == 2) 
        {
            int X;
            cin >> X;
            machine.push(X); 
        } 
        else if (command == 3) 
        {
            if (!machine.empty()) 
            {
                machine.pop(); 
            }
        }
    }

    return 0;
}
