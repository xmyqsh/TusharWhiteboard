/**
 * https://www.youtube.com/watch?v=hgA4xxlVvfQ
 * http://www.geeksforgeeks.org/dynamic-programming-set-24-optimal-binary-search-tree/
 */

#include "../tools/tools.h"

// Memorization
int optCostMemorization(const vector<int>& freq, const vector<int>& freqSum, vector<vector<int> >& cache, int i, int j) {
    if (i > j) return 0;
    if (cache[i][j] != INT_MAX) return cache[i][j];
    for (int k = i; k <= j; ++k)
        cache[i][j] = min(cache[i][j], optCostMemorization(freq, freqSum, cache, i, k - 1) +
                                        optCostMemorization(freq, freqSum, cache, k + 1, j));
    cache[i][j] += freqSum[j + 1] - freqSum[i];
    return cache[i][j];
}

// DP
int optCostDp(const vector<int>& freq, const vector<int>& freqSum) {
    vector<vector<int> > dp(freq.size(), vector<int>(freq.size(), INT_MAX));
    for (int i = 0; i != freq.size(); ++i) dp[i][i] = freq[i];
    for (int l = 1; l != freq.size(); ++l) {
        for (int i = 0, j = l; j != freq.size(); ++i, ++j) {
            for (int k = i; k <= j; ++k)
                dp[i][j] = min(dp[i][j], (k == i ? 0 : dp[i][k - 1]) + (k == j ? 0 : dp[k + 1][j]));
            dp[i][j] += freqSum[j + 1] - freqSum[i];
        }
    }
    return dp[0][freq.size() - 1];
}

int main() {
    vector<int> val = {10,12,16,21};
    vector<int> freq = {4,2,6,3};
    vector<int> freqSum(freq.size() + 1, 0);
    vector<vector<int> > cache(freq.size(), vector<int>(freq.size(), INT_MAX));
    for (int i = 0; i != freq.size(); ++i) freqSum[i + 1] = freqSum[i] + freq[i];
    cout << optCostMemorization(freq, freqSum, cache, 0, freq.size() - 1) << endl;
    cout << optCostDp(freq, freqSum) << endl;
    return 0;
}
