//B
#include<bits/stdc++.h>
using namespace std;
int minTimarOperations(int n,int m,int k, string a)
{
    int operation =0;
    for(int i=0;i<n;)
    {
        if(a[i]=='0')
        {
            operation++;
            i+=k;
        }
        else
        {
            i++;
        }
    }
    return operation;
}

int main()
{
    int t;
    cin>> t;
    while(t--)
    {
        int n,m,k;
        cin>> n >> m >> k;
        string a;
        cin>> a;
        cout << minTimarOperations(n,m,k,a) <<endl;
    }
    return 0;
}