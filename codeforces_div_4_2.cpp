#include <iostream>
#include <stack>
using namespace std;

void solve() {
    string s;
    cin >> s;

    stack<char> st;  

    for (char c : s) {
        if (!st.empty() && st.top() == c) {
            st.pop(); 
        } else {
            st.push(c);
        }
    }

    cout << max(1, (int)st.size()) << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;  

    while (t--) {
        solve();
    }

    return 0;
}
