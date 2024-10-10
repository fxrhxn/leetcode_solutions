#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        if (n <= 1) return 0;

        // Create a boolean array to mark prime numbers
        vector<bool> is_prime(n, true);
        
        // 0 and 1 are not prime
        is_prime[0] = is_prime[1] = false;

        // Sieve of Eratosthenes
        for (int i = 2; i * i < n; ++i) {
            if (is_prime[i]) {
                // Mark multiples of i as non-prime
                for (int j = i * i; j < n; j += i) {
                    is_prime[j] = false;
                }
            }
        }

        // Count the number of primes
        int count = 0;
        for (int i = 2; i < n; ++i) {
            if (is_prime[i]) {
                count++;
            }
        }

        return count;
    }
};

int main() {
    Solution solution;
    
    // Example 1
    int n1 = 10;
    cout << "Example 1 Output: " << solution.countPrimes(n1) << endl; // Output: 4
    
    // Example 2
    int n2 = 0;
    cout << "Example 2 Output: " << solution.countPrimes(n2) << endl; // Output: 0
    
    // Example 3
    int n3 = 1;
    cout << "Example 3 Output: " << solution.countPrimes(n3) << endl; // Output: 0
    
    return 0;
}
