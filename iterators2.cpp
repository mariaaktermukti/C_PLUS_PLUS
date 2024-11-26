#include<bits/stdc++.h>
using namespace std;
int main(){
   string s="Hello world";
//    for(int i=0;i<s.size();i++){
//         cout<< s[i] <<endl;
//    }

// for(string:: iterator it = s.begin();it<s.end();it++)
// {
//     cout << *it << endl;
// }
for(auto it = s.begin();it<s.end();it++)
{
    cout << *it << endl;
}
// cout << *s.begin() << endl;
// cout << *(s.end()-1) << endl;
   
    return 0;
}