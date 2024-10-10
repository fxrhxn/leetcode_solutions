#include <iostream>
#include <string>
#include <numeric>  // Include this for std::gcd in C++17

using namespace std;

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        // Check if str1 + str2 is equal to str2 + str1
        if (str1 + str2 != str2 + str1) {
            return "";
        }
        // Compute the GCD of the lengths of str1 and str2
        int gcdLength = std::gcd(str1.length(), str2.length());
        // Return the prefix of str1 with length equal to gcdLength
        return str1.substr(0, gcdLength);
    }
};

int main() {
    Solution solution;
    
    // Example 1
    string str1 = "ABCABC";
    string str2 = "ABC";
    cout << "Example 1 Output: " << solution.gcdOfStrings(str1, str2) << endl; // Output: "ABC"

    // Example 2
    str1 = "ABABAB";
    str2 = "ABAB";
    cout << "Example 2 Output: " << solution.gcdOfStrings(str1, str2) << endl; // Output: "AB"

    // Example 3
    str1 = "LEET";
    str2 = "CODE";
    cout << "Example 3 Output: " << solution.gcdOfStrings(str1, str2) << endl; // Output: ""
    
    return 0;
}
