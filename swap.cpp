#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int a,b;
    cin>> a>>b;

    // int temp=a;
    // a=b;
    // b=temp;

    swap(a,b);
    cout<<a<<" "<<b<< endl;
    
    return 0;
}