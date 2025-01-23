#include <iostream>
#include <string>
using namespace std;

int main() {
    string S;
    cin >> S;

    string correctCode = "WECNITK";

    if (S == correctCode) 
    {
        cout << "Welcome to Web Club!" << endl;
    } 
    else 
    {
        cout << "Access denied" << endl;
    }

    return 0;
}
