#include <iostream>
#include <cmath>
using namespace std;

bool isVowel(char c) {
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        string S;
        cin >> S;
        
        int vowels = 0, consonants = 0, digits = 0;
        
        // Classify characters into vowels, consonants, and digits
        for (char c : S) {
            if (isVowel(c)) {
                vowels++;
            } else if (isdigit(c)) {
                digits++;
            } else {
                consonants++;
            }
        }
        
        // Calculate the number of boxes needed
        int boxes = 0;
        
        // Boxes for vowels (2 vowels per box)
        boxes += (vowels + 1) / 2;  // Each box can hold at most 2 vowels
        
        // Boxes for consonants (3 consonants per box)
        boxes += (consonants + 2) / 3;  // Each box can hold at most 3 consonants
        
        // Boxes for digits (1 digit per box)
        boxes += digits;  // Each box can hold at most 1 digit
        
        // Output the result for this test case
        cout << boxes << endl;
    }
    
    return 0;
}
