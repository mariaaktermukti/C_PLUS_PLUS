#include <iostream>
#include <string>
using namespace std;

void solve() {
    int T;
    cin >> T; 

    while (T--) 
    {
        int dDSA, dTOC, dDM;
        cin >> dDSA >> dTOC >> dDM;

        int sDSA, sTOC, sDM;
        cin >> sDSA >> sTOC >> sDM;

        int dragonTotal = dDSA + dTOC + dDM;
        int slothTotal = sDSA + sTOC + sDM;

        if (dragonTotal > slothTotal) 
        {
            cout << "Dragon" << endl;
        } 
        else if (slothTotal > dragonTotal) 
        {
            cout << "Sloth" << endl;
        } 
        else 
        {
            if (dDSA > sDSA) 
            {
                cout << "Dragon" << endl;
            } 
            else if (sDSA > dDSA) 
            {
                cout << "Sloth" << endl;
            } 
            else 
            {
                if (dTOC > sTOC) 
                {
                    cout << "Dragon" << endl;
                } 
                else if (sTOC > dTOC) 
                {
                    cout << "Sloth" << endl;
                } 
                else 
                {
                    cout << "Tie" << endl;
                }
            }
        }
    }
}

int main() {
    solve();
    return 0;
}
