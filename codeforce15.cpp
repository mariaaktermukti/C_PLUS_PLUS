#include <iostream>
#include <string>
using namespace std;

int main() {
    string S;
    cin >> S;
    string target = "EGYPT";
    string replacement = " ";

    size_t pos = S.find(target);
    while (pos != string::npos) {
        S.replace(pos, target.length(), replacement);
        pos = S.find(target, pos + 1); 
    }

    cout << S << endl;
    return 0;
}
