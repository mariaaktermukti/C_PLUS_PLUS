#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool is_valid(string s, string A) {
    return s > A && string(s.rbegin(), s.rend()) > A;
}

string find_valid_name(int N, string A) {
    string name = A;
    for (int i = N - 1; i >= 0; --i) {
        if (name[i] < 'z') {
            name[i]++;
            if (is_valid(name, A)) return name;
            name[i]--;
        }
    }
    return "-1";
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        string A;
        cin >> N >> A;
        cout << find_valid_name(N, A) << endl;
    }
    return 0;
}
