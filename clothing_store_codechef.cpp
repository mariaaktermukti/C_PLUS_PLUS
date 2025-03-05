#include <iostream>

using namespace std;

int getMaxHappyPeople(int X, int Y, int Z, int A, int B, int C) {
    int happy = 0;

    int serveS = min(X, A);
    happy += serveS;
    A -= serveS;
    X -= serveS;

    int serveL = min(Y, B);
    happy += serveL;
    B -= serveL;
    Y -= serveL;

    int serveXL = min(Z, C);
    happy += serveXL;
    C -= serveXL;
    Z -= serveXL;

    int convertXLtoL = min(Z, B);
    happy += convertXLtoL;
    B -= convertXLtoL;
    Z -= convertXLtoL;

    int convertXLtoS = min(Z, A);
    happy += convertXLtoS;
    A -= convertXLtoS;
    Z -= convertXLtoS;

    int convertLtoS = min(Y, A);
    happy += convertLtoS;
    A -= convertLtoS;
    Y -= convertLtoS;

    return happy;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int X, Y, Z, A, B, C;
        cin >> X >> Y >> Z >> A >> B >> C;
        cout << getMaxHappyPeople(X, Y, Z, A, B, C) << endl;
    }

    return 0;
}
