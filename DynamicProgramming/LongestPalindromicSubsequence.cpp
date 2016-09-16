/**
 * Date 16/09/2016
 * @author xmyqsh
 *
 * Given a string find longest palindromic subsequence in this string.
 *
 * Time complexity - O(n^2)
 * Space complexity - O(n^2)
 *
 * Youtube link - https://youtu.be/_nCsPn7_OgI
 *
 * References
 * http://www.geeksforgeeks.org/dynamic-programming-set-12-longest-palindromic-subsequence/
 */

#include "../tools/tools.h"

// Memorization
int LPSMemorization(const string& str, vector<vector<int> >& cache, int b, int e) {
    if (b > e) return 0;
    if (b == e) return 1;
    if (cache[b][e] != 0) return cache[b][e];
    if (str[b] == str[e]) cache[b][e] = 2 + LPSMemorization(str, cache, b + 1, e - 1);
    else cache[b][e] = max(LPSMemorization(str, cache, b, e - 1), LPSMemorization(str, cache, b + 1, e));
    return cache[b][e];
}

// DP
int LPSDp(const string& str) {
    vector<vector<int> > dp(str.size(), vector<int>(str.size(), 0));
    for (int i = 0; i != str.size(); ++i) dp[i][i] = 1;
    for (int l = 1; l != str.size(); ++l) {
        for (int i = 0, j = l; j != str.size(); ++i, ++j) {
            if (str[i] == str[j]) dp[i][j] = 2 + dp[i + 1][j - 1];
            else dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
        }
    }
    return dp[0][str.size() - 1];
}

int main() {
    string str = "agbdba";
    vector<vector<int> > cache(str.size(), vector<int>(str.size(), 0));
    cout << LPSMemorization(str, cache, 0, str.size() - 1) << endl;
    cout << LPSDp(str) << endl;
    return 0;
}
