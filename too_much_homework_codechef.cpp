#include <iostream>
using namespace std;

int main() {
    int X, Y;
    cin >> X >> Y;
    
    // Maximum questions Chef can answer additionally
    int max_additional = 10 * Y;
    
    // Check if he can reach at least 100 questions
    if (X + max_additional >= 100) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    
    return 0;
}
