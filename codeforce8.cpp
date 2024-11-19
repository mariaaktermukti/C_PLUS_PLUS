#include <iostream>
#include <cmath>  
using namespace std;

int main() {
    long long A, B, C, D;
    cin >> A >> B >> C >> D;

    double logAB = B * log(A);
    double logCD = D * log(C);


    if (logAB > logCD) {
        cout << "YES" << endl;
    } 
    else {
        cout << "NO" << endl;
    }

    return 0;
}
