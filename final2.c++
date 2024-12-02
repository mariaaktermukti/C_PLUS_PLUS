#include <bits/stdc++.h>
using namespace std;

int main() {
    string S;
    getline(cin, S); 

    string word = "Jessica";
    stringstream ss(S); 
    string currentWord;

    bool found = false;
    while (ss >> currentWord)
     { 
        if (currentWord == word) {
            found = true;
            break;
        }
    }

    if (found) 
    {
        cout << "YES" << endl;
    } 
    else 
    {
        cout << "NO" << endl;
    }

    return 0;
}
