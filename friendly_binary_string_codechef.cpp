#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);

int main() {
    fastio;
    int T;
    cin >> T;
    while(T--) {
        int N; 
        cin >> N;
        string A, B;
        cin >> A >> B;

        long long c00 = 0, c11 = 0, c01 = 0, c10 = 0;
        for (int i = 0; i < N; i++) {
            if (A[i] == '0' && B[i] == '0') c00++;
            else if (A[i] == '1' && B[i] == '1') c11++;
            else if (A[i] == '0' && B[i] == '1') c01++;
            else if (A[i] == '1' && B[i] == '0') c10++;
        }

        auto canFormPalindrome = [&](long long t00, long long t11, long long t01, long long t10) {
            if (t00 % 2 == 0 && t11 % 2 == 0 && ((t01 + t10) % 2 == 0)) {
                return true;
            }
            return false;
        };

        bool possible = false;
        if (N % 2 == 0) {
            if (canFormPalindrome(c00, c11, c01, c10)) {
                possible = true;
            }
        } else {
            long long orig00 = c00, orig11 = c11, orig01 = c01, orig10 = c10;

            auto tryRemove = [&](long long &cnt00, long long &cnt11, 
                                 long long &cnt01, long long &cnt10) {
                if (canFormPalindrome(cnt00, cnt11, cnt01, cnt10)) {
                    possible = true;
                }
            };
            if (c00 > 0) {
                c00--;
                tryRemove(c00, c11, c01, c10);
                c00 = orig00; // restore
            }

            if (!possible && c11 > 0) {
                c11--;
                tryRemove(c00, c11, c01, c10);
                c11 = orig11; // restore
            }

            if (!possible && c01 > 0) {
                c01--;
                tryRemove(c00, c11, c01, c10);
                c01 = orig01; // restore
            }
            if (!possible && c10 > 0) {
                c10--;
                tryRemove(c00, c11, c01, c10);
                c10 = orig10; // restore
            }
        }

        cout << (possible ? "YES\n" : "NO\n");
    }
    return 0;
}
