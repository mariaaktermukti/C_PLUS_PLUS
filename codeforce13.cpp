#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string S;
    cin >> S;

    transform(S.begin(), S.end(), S.begin(), ::toupper);
    int freq[26] = {0};
    for (char ch : S) {
        freq[ch - 'A']++;
    }
    int min_count = freq['E' - 'A'];
    min_count = min(min_count, freq['G' - 'A']); 
    min_count = min(min_count, freq['Y' - 'A']);
    min_count = min(min_count, freq['P' - 'A']);
    min_count = min(min_count, freq['T' - 'A']); 

    cout << min_count << endl;

    return 0;
}
