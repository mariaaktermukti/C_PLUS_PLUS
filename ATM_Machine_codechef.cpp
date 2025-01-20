#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() 
{
    int T;
    cin >> T;

    while (T--) 
    {
        int N, K;
        cin >> N >> K;

        vector<int> A(N);
        for (int i = 0; i < N; ++i) 
        {
            cin >> A[i];
        }

        string result = "";
        for (int i = 0; i < N; ++i) 
        {
            if (K >= A[i]) 
            {
                K -= A[i];
                result += '1';
            } 
            else 
            {
                result += '0';
            }
        }

        cout << result << endl;
    }

    return 0;
}
