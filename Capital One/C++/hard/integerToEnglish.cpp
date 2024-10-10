#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string numberToWords(int num) {
        if (num == 0) return "Zero"; // Handle zero case
        return helper(num).substr(1); // Call helper and remove leading space
    }

private:
    // Helper function to convert numbers to words
    string helper(int num) {
        vector<string> belowTwenty = {
            "", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine",
            "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen",
            "Seventeen", "Eighteen", "Nineteen"
        };
        vector<string> tens = {
            "", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"
        };
        vector<string> thousands = {
            "", "Thousand", "Million", "Billion"
        };

        string words;
        int i = 0;

        // Process each group of three digits
        while (num > 0) {
            if (num % 1000 != 0) {
                words = helperLessThanThousand(num % 1000) + thousands[i] + " " + words;
            }
            num /= 1000;
            i++;
        }
        
        return words;
    }

    // Convert numbers less than 1000 to words
    string helperLessThanThousand(int num) {
        vector<string> belowTwenty = {
            "", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine",
            "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen",
            "Seventeen", "Eighteen", "Nineteen"
        };
        vector<string> tens = {
            "", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"
        };

        string words;

        if (num >= 100) {
            words += belowTwenty[num / 100] + " Hundred ";
            num %= 100;
        }
        if (num >= 20) {
            words += tens[num / 10] + " ";
            num %= 10;
        }
        if (num > 0) {
            words += belowTwenty[num] + " ";
        }

        return words;
    }
};

// Example usage
int main() {
    Solution solution;
    
    cout << "Input: 123, Output: \"" << solution.numberToWords(123) << "\"" << endl; // "One Hundred Twenty Three"
    cout << "Input: 12345, Output: \"" << solution.numberToWords(12345) << "\"" << endl; // "Twelve Thousand Three Hundred Forty Five"
    cout << "Input: 1234567, Output: \"" << solution.numberToWords(1234567) << "\"" << endl; // "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"
    
    return 0;
}
