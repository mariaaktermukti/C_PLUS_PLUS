#include <iostream>
#include <string>

using namespace std;

const string TARGET = "ADVITIYA"; 

int minOperations(string S) {
    int steps = 0;
    for (int i = 0; i < 8; i++) {
        char currentChar = S[i];
        char targetChar = TARGET[i];

        int forwardShift = (targetChar - currentChar + 26) % 26;  

        steps += forwardShift; 
    }
    return steps;
}

int main() {
    int T;
    cin >> T; 

    while (T--) {
        string S;
        cin >> S; 

        cout << minOperations(S) << endl; 
    }

    return 0;
}
