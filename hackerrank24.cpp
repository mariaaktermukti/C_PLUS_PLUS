#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main() 
{
    int q;
    cin >> q;

    queue<string> ticketLine; 

    while (q--) 
    {
        int command;
        cin >> command;

        if (command == 0) 
        {
            string name;
            cin >> name;
            ticketLine.push(name);
        } 
        else if (command == 1) 
        {
            if (ticketLine.empty()) 
            {
                cout << "Invalid" << endl;
            } 
            else 
            {
                cout << ticketLine.front() << endl;
                ticketLine.pop();
            }
        } 
        else 
        {
            cout << "Invalid Command" << endl;
        }
    }

    return 0;
}
