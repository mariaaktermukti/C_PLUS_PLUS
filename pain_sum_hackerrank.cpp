#include <iostream>
using namespace std;

long long sumToPosition(long long pos) 
{
    long long block = (pos - 1) / 3;
    long long sum = (block + 1) * block * 3 / 2; 
    sum += (pos - block * 3) * (block + 1); 
    return sum;
}

int main() 
{
    long long N, Q;
    cin >> N >> Q;

    while (Q--) 
    {
        long long L, R;
        cin >> L >> R;

        long long sumLtoR = sumToPosition(R) - sumToPosition(L - 1);
        cout << sumLtoR << endl;
    }

    return 0;
}
