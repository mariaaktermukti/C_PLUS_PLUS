#include<bits/stdc++.h>
using namespace std;
void fun(int* &p)
{
    cout << "in fun : " << *p << endl;
}
int main()
{
   int x=10;
   int* p= &x;
   fun(p);
       cout << "in main : " << *p << endl;
    return 0; 
}