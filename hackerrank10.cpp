#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    for (int i = 0; i < N / 2; i++) {
        for (int j = 0; j < i; j++) {
            cout << " ";
        }
        cout << "\\";
        for (int j = 0; j < N - 2 * (i + 1); j++) {
            cout << " ";
        }
        cout << "/" << endl;
    }
    for (int i = 0; i < N / 2; i++) {
        cout << " ";
    }
    cout << "X" << endl;
    for (int i = N / 2 - 1; i >= 0; i--) {
        for (int j = 0; j < i; j++) {
            cout << " ";
        }
        cout << "/";
        for (int j = 0; j < N - 2 * (i + 1); j++) {
            cout << " ";
        }
        cout << "\\" << endl;
    }

    return 0;
}
