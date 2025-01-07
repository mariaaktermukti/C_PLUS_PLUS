#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class RangeFreqQuery {
private:
    unordered_map<int, vector<int>> valueIndices;

public:
    RangeFreqQuery(vector<int>& arr) 
    {
        for (int i = 0; i < arr.size(); ++i) 
        {
            valueIndices[arr[i]].push_back(i);
        }
    }

    int query(int left, int right, int value) 
    {
        if (valueIndices.find(value) == valueIndices.end()) 
        {
            return 0; 
        }
        
        const vector<int>& indices = valueIndices[value];

        auto leftIt = lower_bound(indices.begin(), indices.end(), left);

        auto rightIt = upper_bound(indices.begin(), indices.end(), right);

        return rightIt - leftIt;
    }
};

int main() {
    vector<int> arr = {12, 33, 4, 56, 22, 2, 34, 33, 22, 12, 34, 56};
    RangeFreqQuery rangeFreqQuery(arr);

    cout << rangeFreqQuery.query(1, 2, 4) << endl;  
    cout << rangeFreqQuery.query(0, 11, 33) << endl; 

    return 0;
}
