#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int main() 
{
    int Q;
    cin >> Q;
    cin.ignore(); 

    vector<string> playlist;

    while (Q--) 
    {
        string command;
        getline(cin, command);
        stringstream ss(command);
        
        string operation;
        ss >> operation; 

        if (operation == "ADD") 
        {
            int pos;
            string song;
            ss >> pos >> song;

            if (pos < 0 || pos > playlist.size()) 
            {
                cout << "Invalid" << endl;
            } 
            else 
            {
                playlist.insert(playlist.begin() + pos, song);
            }
        } 
        else if (operation == "DELETE") 
        {
            int pos;
            ss >> pos;

            if (pos < 0 || pos >= playlist.size()) 
            {
                cout << "Invalid" << endl;
            } 
            else 
            {
                playlist.erase(playlist.begin() + pos);
            }
        } 
        else if (operation == "PRINT") 
        {
            if (playlist.empty()) 
            {
                cout << "EMPTY" << endl;
            } 
            else 
            {
                for (size_t i = 0; i < playlist.size(); i++) 
                {
                    if (i > 0) cout << " ";
                    cout << playlist[i];
                }
                cout << endl;
            }
        }
    }

    return 0;
}
