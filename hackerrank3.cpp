#include <bits/stdc++.h>
using namespace std;

int main()
{
    string S;
    while(getline(cin,S))
    {
        S.erase(remove(S.begin(), S.end(),' '), S.end());
        sort(S.begin(), S.end());
        cout << S << endl;
    }
    return 0;
}