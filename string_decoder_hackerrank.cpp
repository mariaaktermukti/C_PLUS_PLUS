#include <iostream>
#include <string>
using namespace std;

int main() 
{
    int T;
    cin >> T;
    while (T--) 
    {
        string encoded;
        cin >> encoded;
        
        size_t final_length = 0;
        for (size_t i = 1; i < encoded.size(); i += 2) 
        {
            final_length += encoded[i] - '0';
        }
        
        string decoded;
        decoded.reserve(final_length);

        for (size_t i = 0; i < encoded.size(); i += 2) 
        {
            char letter = encoded[i];
            int count = encoded[i + 1] - '0';  
            decoded.append(count, letter);
        }
        
        cout << decoded << "\n";
    }
    return 0;
}
