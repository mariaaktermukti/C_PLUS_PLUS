//s.begin()-> pointer to the first element
//s.end()-> pointer to the next element after the last element of the string.

#include<bits/stdc++.h>
using namespace std;
int main(){
   string s="Hello world";
//    for(int i=0;i<s.size();i++){
//         cout<< s[i] <<endl;
//    }
cout << *s.begin() << endl;
cout << *(s.end()-1) << endl;
   
    return 0;
}