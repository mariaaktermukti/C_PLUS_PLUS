#include <iostream>
#include <string>
using namespace std;

void swapAdjacent(string &s, int n) 
{
    for (int i = 0; i < n - 1; i += 2) 
    {
        swap(s[i], s[i + 1]);
    }
}

void replaceWithReverse(string &s) 
{
    for (char &c : s) 
    {
        c = 'a' + ('z' - c);
    }
}

int main() 
{
    int T;
    cin >> T;
    
    while (T--) 
    {
        int N;
        string S;
        cin >> N >> S;
        
        swapAdjacent(S, N);
        replaceWithReverse(S);
        
        cout << S << endl;
    }
    
    return 0;
}
