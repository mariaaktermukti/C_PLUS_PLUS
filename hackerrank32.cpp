#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

typedef pair<string, int> StringIntPair;

bool customComparator(const StringIntPair &a, const StringIntPair &b) 
{
    if (a.first == b.first) 
    {
        return a.second > b.second;
    }
    return a.first < b.first;
}

int main() 
{
    int n; 
    cin >> n;

    vector<StringIntPair> pairs(n);

    for (int i = 0; i < n; i++) 
    {
        cin >> pairs[i].first >> pairs[i].second;
    }

    sort(pairs.begin(), pairs.end(), customComparator);

    for (const auto &p : pairs) 
    {
        cout << p.first << " " << p.second << endl;
    }

    return 0;
}
