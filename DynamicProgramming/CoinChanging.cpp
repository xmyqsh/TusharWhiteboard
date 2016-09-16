/**
 * @Date 16/09/2016
 * @author xmyqsh
 *
 * Given a total and coins of certain denominations find number of ways total
 * can be formed from coins assuming infinity supply of coins
 *
 * References:
 * https://www.youtube.com/watch?v=_fgjrs570YE
 * http://www.geeksforgeeks.org/dynamic-programming-set-7-coin-change/
 *
 * Help: Anyone come up with Memorization version?
 *
 */

#include "../tools/tools.h"

// Recursion
int numsOfCoinChangingRecursion(const vector<int>& coins, int remain, int maxIdx) {
    if (remain == 0) return 1;
    if (remain < 0 || maxIdx < 0) return 0;
    int result = 0;
    for (int i = maxIdx; i >= 0; --i)
        result += numsOfCoinChangingRecursion(coins, remain - coins[i], i);
    return result;
}

// DP1
int numsOfCoinChangingDp1(const vector<int>& coins, int total) {
    vector<int> dp(total + 1, 0); dp[0] = 1;
    for (auto coin : coins) {
        vector<int> dpBk(dp);
        for (int i = coin; i <= total; ++i)
            dp[i] += dp[i - coin];
    }
    return dp[total];
}

int main() {
    vector<int> coins = {1,2,3};
    int total = 5;
    cout << numsOfCoinChangingRecursion(coins, total, coins.size() - 1) << endl;
    cout << numsOfCoinChangingDp1(coins, total) << endl;
    return 0;
}
