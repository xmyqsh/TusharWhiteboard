/**
 * Date 16/09/2016
 * @author xmyqsh
 *
 * Given a total and coins of certain denomination with infinite supply, what is the minimum number
 * of coins it takes to form this total.
 *
 * Time complexity - O(coins.size * total)
 * Space complexity - O(coins.size * total)
 *
 * Youtube video -
 * Topdown DP - https://www.youtube.com/watch?v=NJuKJ8sasGk
 * Bottom up DP - https://youtu.be/Y0ZqKpToTic
 */

#include "../tools/tools.h"

// Memorization
int minCoinMemorization(const vector<int>& coins, int total, vector<int>& cache, int remain) {
    if (remain == 0) return 0;
    if (cache[remain] != total + 1) return cache[remain];
    for (auto coin : coins)
        if (remain >= coin)
            cache[remain] = min(cache[remain], 1 + minCoinMemorization(coins, total, cache, remain - coin));
    return cache[remain];
}

// Dp
int minCoinDp(const vector<int>& coins, int total) {
    vector<int> dp(total + 1, total + 1); dp[0] = 0;
    for (auto coin : coins)
        for (int v = coin; v <= total; ++v)
            dp[v] = min(dp[v], 1 + dp[v - coin]);
    return dp[total];
}

int main() {
    vector<int> coins = {7, 3, 2, 6};
    int total = 13;
    vector<int> cache(total + 1, total + 1);
    cout << minCoinMemorization(coins, total, cache, total) << endl;
    cout << minCoinDp(coins, total) << endl;
    return 0;
}
