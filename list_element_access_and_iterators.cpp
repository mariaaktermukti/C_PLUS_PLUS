#include<bits/stdc++.h>
using namespace std;
int main()
{
    list<int> l={20,30,10,50,30,60,60,10};

    cout<< l.back() << endl;

    cout << l.front() << endl;

    cout<<*next(l.begin(),2) << endl;

    cout<< *l.begin() << endl;

    return 0;
}