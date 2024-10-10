#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        
        // Start from the last digit and work backwards
        for (int i = n - 1; i >= 0; --i) {
            if (digits[i] < 9) {
                // If the current digit is less than 9, just add one and return
                digits[i]++;
                return digits;
            }
            // If the digit is 9, set it to 0 and continue the loop for carry
            digits[i] = 0;
        }
        
        // If all digits were 9, we need to add a new leading 1
        digits.insert(digits.begin(), 1);
        return digits;
    }
};

int main() {
    Solution solution;

    // Example 1
    vector<int> digits1 = {1, 2, 3};
    vector<int> output1 = solution.plusOne(digits1);
    cout << "Example 1 Output: ";
    for (int digit : output1) {
        cout << digit;
    }
    cout << endl; // Output: [1,2,4]
    
    // Example 2
    vector<int> digits2 = {4, 3, 2, 1};
    vector<int> output2 = solution.plusOne(digits2);
    cout << "Example 2 Output: ";
    for (int digit : output2) {
        cout << digit;
    }
    cout << endl; // Output: [4,3,2,2]
    
    // Example 3
    vector<int> digits3 = {9};
    vector<int> output3 = solution.plusOne(digits3);
    cout << "Example 3 Output: ";
    for (int digit : output3) {
        cout << digit;
    }
    cout << endl; // Output: [1,0]

    return 0;
}
