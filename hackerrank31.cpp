//sorted
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main() 
{
    int t; 
    cin >> t;

    while (t--) {
        int n; 
        cin >> n;

        vector<int> nums(n);
        for (int i = 0; i < n; ++i) 
        {
            cin >> nums[i];
        }

        set<int> uniqueNums(nums.begin(), nums.end());

        for (int num : uniqueNums) 
        {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
