#include<bits/stdc++.h>
using namespace std;

int main() 
{
    string s;
    cin >> s;
    
    bool seen[26] = {false};
    
    for (char c : s) 
    {
        seen[c - 'a'] = true;
    }

    for (int i = 0; i < 26; i++) 
    {
        if (seen[i]) 
        {
            cout << char('a' + i);
        }
    }
    
    return 0;
}
