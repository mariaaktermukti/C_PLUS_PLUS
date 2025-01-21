#include <iostream>
#include <vector>
using namespace std;

void solve() 
{
    int T;
    cin >> T; 

    while (T--) 
    {
        int N;
        cin >> N; 
        vector<int> B(N);

        int sumB = 0;
        for (int i = 0; i < N; ++i) 
        {
            cin >> B[i];
            sumB += B[i];
        }

        if (sumB % 2 == 0) 
        {
            cout << "YES" << endl;
        } 
        else 
        {
            cout << "NO" << endl;
        }
    }
}

int main() {
    solve();
    return 0;
}
