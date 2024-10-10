#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> answer;  // Vector to store results
        for (int i = 1; i <= n; ++i) {
            if (i % 3 == 0 && i % 5 == 0) {
                answer.push_back("FizzBuzz");
            } else if (i % 3 == 0) {
                answer.push_back("Fizz");
            } else if (i % 5 == 0) {
                answer.push_back("Buzz");
            } else {
                answer.push_back(to_string(i));  // Convert int to string
            }
        }
        return answer;  // Return the vector of results
    }
};

int main() {
    Solution solution;
    
    // Example 1
    int n1 = 3;
    vector<string> output1 = solution.fizzBuzz(n1);
    cout << "Example 1 Output: ";
    for (const auto& str : output1) {
        cout << str << " ";
    }
    cout << endl; // Output: ["1","2","Fizz"]
    
    // Example 2
    int n2 = 5;
    vector<string> output2 = solution.fizzBuzz(n2);
    cout << "Example 2 Output: ";
    for (const auto& str : output2) {
        cout << str << " ";
    }
    cout << endl; // Output: ["1","2","Fizz","4","Buzz"]
    
    // Example 3
    int n3 = 15;
    vector<string> output3 = solution.fizzBuzz(n3);
    cout << "Example 3 Output: ";
    for (const auto& str : output3) {
        cout << str << " ";
    }
    cout << endl; // Output: ["1","2","Fizz","4","Buzz","Fizz","7","8","Fizz","Buzz","11","Fizz","13","14","FizzBuzz"]
    
    return 0;
}
