#include <iostream>
#include <vector>
#include <unordered_set>
#include <numeric> // Include this header for std::accumulate

using namespace std;

// Function to calculate the sum of divisors of numbers with exactly four divisors
int sumOfFourDivisors(const vector<int>& nums) {
    int totalSum = 0;

    for (int num : nums) {
        unordered_set<int> divisors;
        for (int i = 1; i * i <= num; ++i) {
            if (num % i == 0) {
                divisors.insert(i); // Add the divisor
                divisors.insert(num / i); // Add the complement divisor
            }
        }
        // Check if the number of divisors is exactly 4
        if (divisors.size() == 4) {
            // Calculate the sum of the divisors
            totalSum += accumulate(divisors.begin(), divisors.end(), 0);
        }
    }
    
    return totalSum;
}

// Example usage
int main() {
    vector<int> nums1 = {21, 4, 7};
    vector<int> nums2 = {21, 21};
    vector<int> nums3 = {1, 2, 3, 4, 5};

    cout << "Example 1 Output: " << sumOfFourDivisors(nums1) << endl; // Output: 32
    cout << "Example 2 Output: " << sumOfFourDivisors(nums2) << endl; // Output: 64
    cout << "Example 3 Output: " << sumOfFourDivisors(nums3) << endl; // Output: 0

    return 0;
}
