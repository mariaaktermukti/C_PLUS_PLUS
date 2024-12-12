#include <iostream>
#include <vector>
using namespace std;

int main() {
    int T; 
    cin >> T;

    while (T--) {
        int N; 
        cin >> N;

        vector<int> Arr(N); 
        for (int i = 0; i < N; i++) {
            cin >> Arr[i];
        }

        
        int flag = 1;
        for (int i = 1; i < N; i++) {
            if (Arr[i] < Arr[i - 1]) {
                flag = 0; 
                break;
            }
        }

        if (flag == 1)
        {
            cout << "YES" << endl;
        } 
        else 
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}
