#include<bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T; 
    cin.ignore(); 

    while (T--) {
        string S, X;
        getline(cin, S, ' ');
        getline(cin, X);  

        string result = ""; 
        for (size_t i = 0; i < S.size();) {
            if (S.substr(i, X.size()) == X) {
                result += "#"; 
                i += X.size(); 
            } 
            else {
                result += S[i]; 
                i++; 
            }
        }
        
        cout << result << endl;
    }

    return 0;
}
