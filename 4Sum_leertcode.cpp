#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        int n = nums.size();
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 3; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            for (int j = i + 1; j < n - 2; ++j) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;

                int left = j + 1, right = n - 1;
                while (left < right) {
                    long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];
                    if (sum == target) {
                        result.push_back({nums[i], nums[j], nums[left], nums[right]});

                        while (left < right && nums[left] == nums[left + 1]) ++left;
                        while (left < right && nums[right] == nums[right - 1]) --right;

                        ++left;
                        --right;
                    } else if (sum < target) {
                        ++left; 
                    } else {
                        --right; 
                    }
                }
            }
        }
        return result;
    }
};

int main() {
    Solution solution;

    vector<int> nums1 = {1, 0, -1, 0, -2, 2};
    int target1 = 0;
    vector<vector<int>> result1 = solution.fourSum(nums1, target1);

    cout << "Test Case 1:" << endl;
    for (const auto& quadruplet : result1) {
        cout << "[";
        for (int num : quadruplet) {
            cout << num << " ";
        }
        cout << "]" << endl;
    }

    vector<int> nums2 = {2, 2, 2, 2, 2};
    int target2 = 8;
    vector<vector<int>> result2 = solution.fourSum(nums2, target2);

    cout << "Test Case 2:" << endl;
    for (const auto& quadruplet : result2) {
        cout << "[";
        for (int num : quadruplet) {
            cout << num << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}