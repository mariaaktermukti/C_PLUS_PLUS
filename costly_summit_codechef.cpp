#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);

int solve(int N, int C, string &S) {
    unordered_set<char> languages(S.begin(), S.end());
    int unique_langs = languages.size();

    int translator_cost = (N * (N + 1)) / 2;
    
    int learn_and_translate = C + ((N - 1) * N) / 2;
    
    int learn_all = unique_langs * C;
    
    return min({translator_cost, learn_and_translate, learn_all});
}

int main() {
    fastio;
    int T;
    cin >> T;
    while (T--) {
        int N, C;
        cin >> N >> C;
        string S;
        cin >> S;
        cout << solve(N, C, S) << '\n';
    }
    return 0;
}
