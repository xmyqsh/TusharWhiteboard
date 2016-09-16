/*
 * Date 09/16/2016
 * @author myqsh
 *
 * Given an array of non negative numbers and a total, is there subset of numbers in this array which adds up
 * to given total. Another variation is given an array is it possible to split it up into 2 equal
 * sum partitions. Partition need not be equal sized. Just equal sum.
 *
 * Time complexity - O(input.size * total_sum)
 * Space complexity - O(input.size * total_sum)
 *
 * Youtube video - https://youtu.be/s6FhG--P7z0
 */

#include "../tools/tools.h"

bool subSetHasSumDp(const vector<int>& vec, int sum) {
    vector<bool> dp(sum + 1, false); dp[0] = true;
    for (int i = 0; i != vec.size(); ++i)
        for (int s = 1; s <= sum; ++s)
            dp[s] = s < vec[i] ? dp[s] : (dp[s] | dp[s - vec[i]]);
    return dp[sum];
}

bool subSetHasSumBacktracking(const vector<int>& vec, int sum, int curIdx, int curSum) {
    if (curSum == sum) return true;
    if (curSum > sum || curIdx == vec.size()) return false;
    return subSetHasSumBacktracking(vec, sum, curIdx + 1, curSum) ||
            subSetHasSumBacktracking(vec, sum, curIdx + 1, curSum + vec[curIdx]);
}

int main() {
    vector<int> vec = {2, 3, 7, 8, 10};
    int sum = 11;
    cout << subSetHasSumDp(vec, sum) << endl;
    cout << subSetHasSumBacktracking(vec, sum, 0, 0) << endl;
    return 0;
}
