#include <bits/stdc++.h>
using namespace std;

bool isEasyToPronounce(const string& s) 
{
    unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
    int consecutiveConsonants = 0;

    for (char c : s) 
    {
        if (vowels.count(c)) 
        {
            consecutiveConsonants = 0;
        } 
        else 
        {
            consecutiveConsonants++;
            if (consecutiveConsonants >= 4) 
            {
                return false; 
            }
        }
    }
    return true; 
}

int main() 
{
    int T;
    cin >> T;

    while (T--) 
    {
        int N;
        cin >> N;
        string S;
        cin >> S;

        if (isEasyToPronounce(S)) 
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
