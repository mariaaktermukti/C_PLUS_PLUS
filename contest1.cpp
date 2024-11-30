//A

#include<bits/stdc++.h>
using namespace std;

long long findSmallestM(int a, int b)
{
    long long m= max(a,b);
    while(m%a !=m %b)
    {
        m++;
    }
    return m;
}

int main()
{
    int t;
    cin>> t;
    while(t--)
    {
        int a,b;
        cin>>a >> b;
        cout << findSmallestM(a,b) << endl;
    }
    return 0;

}