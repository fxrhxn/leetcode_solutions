#include <iostream>
#include <vector>
#include <algorithm> // For std::max

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_current = nums[0];
        int max_global = nums[0];
        
        for (size_t i = 1; i < nums.size(); ++i) {
            max_current = max(nums[i], max_current + nums[i]);
            if (max_current > max_global) {
                max_global = max_current;
            }
        }
        
        return max_global;
    }
};

int main() {
    Solution solution;

    // Example 1
    vector<int> nums1 = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << "Example 1 Output: " << solution.maxSubArray(nums1) << endl; // Output: 6

    // Example 2
    vector<int> nums2 = {1};
    cout << "Example 2 Output: " << solution.maxSubArray(nums2) << endl; // Output: 1

    // Example 3
    vector<int> nums3 = {5, 4, -1, 7, 8};
    cout << "Example 3 Output: " << solution.maxSubArray(nums3) << endl; // Output: 23

    return 0;
}
