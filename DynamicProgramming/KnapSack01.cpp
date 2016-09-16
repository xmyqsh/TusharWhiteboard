/**
 * Date 09/16/2016
 * @author myqsh
 *
 * 0/1 Knapsack Problem - Given items of certain weights/values and maximum allowed weight
 * how to pick items to pick items from this set to maximize sum of value of items such that
 * sum of weights is less than or equal to maximum allowed weight.
 *
 * Time complexity - O(W*total items)
 *
 * Youtube link
 * Topdown DP - https://youtu.be/149WSzQ4E1g
 * Bottomup DP - https://youtu.be/8LusJS5-AGo
 *
 * References -
 * https://www.youtube.com/watch?v=8LusJS5-AGo
 * http://www.geeksforgeeks.org/dynamic-programming-set-10-0-1-knapsack-problem/
 * https://en.wikipedia.org/wiki/Knapsack_problem
 */

#include "../tools/tools.h"

// recursion
int knapSack01Recursion(const vector<int>& weight, const vector<int>& value, int remainW, int curItem) {
    if (curItem == weight.size() || remainW == 0) return 0;
    if (weight[curItem] > remainW) return knapSack01Recursion(weight, value, remainW, curItem + 1);
    return max(knapSack01Recursion(weight, value, remainW, curItem + 1),
                knapSack01Recursion(weight, value, remainW - weight[curItem], curItem + 1) + value[curItem]);
}

// memorization
int knapSack01Memorization(const vector<int>& weight, const vector<int>& value, int remainW, int curItem, vector<vector<int> >& cache) {
    if (curItem == weight.size() || remainW == 0) return 0;
    int remainItem = weight.size() - curItem - 1;
    if (cache[remainW][remainItem] != -1) return cache[remainW][remainItem];
    if (weight[curItem] > remainW) cache[remainW][remainItem] = knapSack01Memorization(weight, value, remainW, curItem + 1, cache);
    else cache[remainW][remainItem] = max(knapSack01Memorization(weight, value, remainW, curItem + 1, cache),
                    knapSack01Memorization(weight, value, remainW - weight[curItem], curItem + 1, cache) + value[curItem]);
    return cache[remainW][remainItem];
}

// dp1
int knapSack01Dp1(const vector<int>& weight, const vector<int>& value, int maxW) {
    vector<int> dp(maxW + 1, 0);
    for (int i = 0; i != weight.size(); ++i) {
        vector<int> dpBk(dp);
        for (int w = weight[i]; w <= maxW; ++w)
            dp[w] = max(dpBk[w], dpBk[w - weight[i]] + value[i]);
    }
    return dp[maxW];
}

// dp2
int knapSack01Dp2(const vector<int>& weight, const vector<int>& value, int maxW) {
    vector<int> dp(maxW + 1, 0);
    for (int i = 0; i != weight.size(); ++i)
        for (int w = maxW; w >= weight[i]; --w)
            dp[w] = max(dp[w], dp[w - weight[i]] + value[i]);
    return dp[maxW];
}

int main() {
    vector<int> weight = {4, 2, 3, 5, 5, 6, 9, 7, 8, 10};
    vector<int> value = {22, 20, 15, 30, 24, 54, 21, 32, 18, 25};
    int W = 30;
    cout << knapSack01Recursion(weight, value, W, 0) << endl;
    vector<vector<int> > cache(W + 1, vector<int>(weight.size() + 1, -1));
    cout << knapSack01Memorization(weight, value, W, 0, cache) << endl;
    cout << knapSack01Dp1(weight, value, W) << endl;
    cout << knapSack01Dp2(weight, value, W) << endl;
    return 0;
}
