#include <iostream>
#include <string>
using namespace std;

int main() {
    string S;
    cin >> S;
    int freq[26] = {0};

    for (char ch : S) {
        freq[ch - 'a']++;
    }

    for (int i = 0; i < 26; i++) {
        if (freq[i] > 0) {
            cout << char(i + 'a') << " : " << freq[i] << endl;
        }
    }

    return 0;
}
