#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int coinChange(std::vector<int>& coins, int amount) {
        // Create a dp array of size amount + 1, initialized with a large number
        std::vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0; // No coins are needed to make amount 0

        // Iterate through each coin
        for (int coin : coins) {
            // Update the dp array for each possible amount from coin to amount
            for (int i = coin; i <= amount; ++i) {
                dp[i] = std::min(dp[i], dp[i - coin] + 1);
            }
        }

        // If dp[amount] is still amount + 1, it means we cannot make that amount
        return (dp[amount] == amount + 1) ? -1 : dp[amount];
    }
};

// Main function to test the solution
int main() {
    Solution solution;

    // Test case 1
    std::vector<int> coins1 = {1, 2, 5};
    int amount1 = 11;
    std::cout << "Input: coins = [1,2,5], amount = 11\n";
    std::cout << "Output: " << solution.coinChange(coins1, amount1) << "\n"; // Output: 3

    // Test case 2
    std::vector<int> coins2 = {2};
    int amount2 = 3;
    std::cout << "Input: coins = [2], amount = 3\n";
    std::cout << "Output: " << solution.coinChange(coins2, amount2) << "\n"; // Output: -1

    // Test case 3
    std::vector<int> coins3 = {1};
    int amount3 = 0;
    std::cout << "Input: coins = [1], amount = 0\n";
    std::cout << "Output: " << solution.coinChange(coins3, amount3) << "\n"; // Output: 0

    return 0;
}
