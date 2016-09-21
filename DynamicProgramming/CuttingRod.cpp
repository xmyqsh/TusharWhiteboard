/**
 * Given a rod of length and prices at which different length of this rod can sell,
 * how do you cut this rod to maximize profit
 * https://www.youtube.com/watch?v=IRwVmTmN6go
 * http://www.geeksforgeeks.org/dynamic-programming-set-13-cutting-a-rod/
 */

#include "../tools/tools.h"

int maxProfitMemorization(const vector<int>& prices, int remain, vector<int>& cache) {
    if (remain == 0) return 0;
    if (cache[remain]) return cache[remain];
    for (int i = min(remain, (int)prices.size()); i > 0; --i)
        cache[remain] = max(cache[remain], prices[i - 1] + maxProfitMemorization(prices, remain - i, cache));
    return cache[remain];
}

int maxProfitDp(const vector<int>& prices, int len) {
    vector<int> dp(len + 1, 0);
    for (int i = 0; i != prices.size(); ++i)
        for (int j = i + 1; j <= len; ++j)
            dp[j] = max(dp[j], prices[i] + dp[j - i - 1]);
    return dp[len];
}

int main() {
    int len = 5;
    vector<int> prices = {2,5,7,8};
    vector<int> cache(len + 1, 0);
    cout << maxProfitMemorization(prices, len, cache) << endl;
    cout << maxProfitDp(prices, len) << endl;
    return 0;
}
