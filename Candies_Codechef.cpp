#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void solve() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        int n;
        cin >> n;
        
        vector<int> a(2 * n);
        unordered_map<int, int> freq;

        for (int i = 0; i < 2 * n; ++i) 
        {
            cin >> a[i];
            freq[a[i]]++;
        }

        bool isValid = true;
        for (const auto &[key, count] : freq) 
        {
            if (count > 2) 
            { 
                isValid = false;
                break;
            }
        }

        if (isValid) 
        {
            cout << "YES" << endl;
        }
        else 
        {
            cout << "NO" << endl;
        }
    }
}

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
    return 0;
}
