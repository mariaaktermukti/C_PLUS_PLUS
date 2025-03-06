#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    int T;
    cin >> T;
    
    while(T--){
        string s1, s2;
        cin >> s1 >> s2;
        
        string sorted1 = s1;
        string sorted2 = s2;
        
        sort(sorted1.begin(), sorted1.end());
        sort(sorted2.begin(), sorted2.end());
        
        if(sorted1 == sorted2)
            cout << "YES" << "\n";
        else
            cout << "NO" << "\n";
    }
    
    return 0;
}
