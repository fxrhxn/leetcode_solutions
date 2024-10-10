#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ranges;

        if (nums.empty()) {
            return ranges; // Return an empty vector if the input is empty
        }

        int start = nums[0]; // Start of the current range

        for (int i = 1; i <= nums.size(); ++i) {
            // Check if we are at the end of the array or if the current number is not consecutive
            if (i == nums.size() || nums[i] != nums[i - 1] + 1) {
                // If start equals the end, it's a single number
                if (start == nums[i - 1]) {
                    ranges.push_back(to_string(start));
                } else {
                    // Otherwise, it's a range
                    ranges.push_back(to_string(start) + "->" + to_string(nums[i - 1]));
                }
                // Update the start to the current number
                if (i < nums.size()) {
                    start = nums[i];
                }
            }
        }

        return ranges;
    }
};

// Main function to test the solution
int main() {
    Solution solution;

    // Example 1
    vector<int> nums1 = {0, 1, 2, 4, 5, 7};
    vector<string> result1 = solution.summaryRanges(nums1);
    cout << "Example 1 Output: ";
    for (const auto& range : result1) {
        cout << range << " ";
    }
    cout << endl; // Output: ["0->2","4->5","7"]

    // Example 2
    vector<int> nums2 = {0, 2, 3, 4, 6, 8, 9};
    vector<string> result2 = solution.summaryRanges(nums2);
    cout << "Example 2 Output: ";
    for (const auto& range : result2) {
        cout << range << " ";
    }
    cout << endl; // Output: ["0","2->4","6","8->9"]

    return 0;
}
