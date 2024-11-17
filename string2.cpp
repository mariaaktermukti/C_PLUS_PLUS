#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int x;
    cin>>x;
    cin.ignore();
    char s[100];
    cin.getline(s,100);
    cout<<x<<endl<<s<<endl;
    return 0;
}