/**
 * Given some matrices, in what order you would multiply them to minimize cost of multiplication.
 * https://www.youtube.com/watch?v=vgLJZMUfnsU
 * http://www.geeksforgeeks.org/dynamic-programming-set-8-matrix-chain-multiplication/
 */

#include "../tools/tools.h"

int minCost(const vector<int>& arr) {
    vector<vector<int> > dp(arr.size(), vector<int>(arr.size(), INT_MAX));
    for (int i = 0; i != arr.size(); ++i) { dp[i][i] = 0; dp[i][i + 1] = 0; }
    for (int l = 2; l < arr.size(); ++l) {
        for (int i = 0, j = l; j != arr.size(); ++i, ++j) {
            for (int t = i + 1; t < j; ++t)
                dp[i][j] = min(dp[i][j], dp[i][t] + arr[i] * arr[t] * arr[j] + dp[t][j]);
        }
    }
    return dp[0][arr.size() - 1];
}

int main() {
    vector<int> arr = {2, 3, 6, 4, 5};
    cout << minCost(arr) << endl;
    return 0;
}
