#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int m = nums1.size();
        int n = nums2.size();
        int low = 0, high = m;

        while (low <= high) {
            int partition1 = (low + high) / 2;
            int partition2 = (m + n + 1) / 2 - partition1;

            int maxLeft1 = (partition1 == 0) ? INT_MIN : nums1[partition1 - 1];
            int minRight1 = (partition1 == m) ? INT_MAX : nums1[partition1];

            int maxLeft2 = (partition2 == 0) ? INT_MIN : nums2[partition2 - 1];
            int minRight2 = (partition2 == n) ? INT_MAX : nums2[partition2];

            if (maxLeft1 <= minRight2 && maxLeft2 <= minRight1) {
                if ((m + n) % 2 == 0) {
                    return (max(maxLeft1, maxLeft2) + min(minRight1, minRight2)) / 2.0;
                } else {
                    return max(maxLeft1, maxLeft2);
                }
            } else if (maxLeft1 > minRight2) {
                high = partition1 - 1; 
            } else {
                low = partition1 + 1; 
            }
        }

        throw invalid_argument("Input arrays are not sorted.");
    }
};

int main() {
    Solution solution;

    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};
    cout << "Median: " << solution.findMedianSortedArrays(nums1, nums2) << endl;

    vector<int> nums1_2 = {1, 2};
    vector<int> nums2_2 = {3, 4};
    cout << "Median: " << solution.findMedianSortedArrays(nums1_2, nums2_2) << endl;

    vector<int> nums1_3 = {0, 0};
    vector<int> nums2_3 = {0, 0};
    cout << "Median: " << solution.findMedianSortedArrays(nums1_3, nums2_3) << endl;

    return 0;
}
