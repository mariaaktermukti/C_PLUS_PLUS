#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>> s;
    string reverse_s=s;
    reverse(reverse_s.begin(), reverse_s.end());
    if(s== reverse_s)
    {
        cout << "YES\n" << endl;
    }
    else
    {
        cout<< "NO" << endl;
    }
    return 0;
}