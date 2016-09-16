/**
 * Given two strings, find longest common subsequence between them.
 * https://www.youtube.com/watch?v=NnD96abizww
 * http://www.geeksforgeeks.org/dynamic-programming-set-4-longest-common-subsequence/
 */

#include "../tools/tools.h"

int LCS1(const string& str1, const string& str2) {
    vector<vector<int> > dp(str1.size() + 1, vector<int>(str2.size() + 1, 0));
    for (int i = 0; i != str1.size(); ++i)
        for (int j = 0; j != str2.size(); ++j)
            dp[i + 1][j + 1] = str1[i] == str2[j] ? dp[i][j] + 1 : max(dp[i][j + 1], dp[i + 1][j]);
    return dp[str1.size()][str2.size()];
}

int LCS2(const string& str1, const string& str2) {
    if (str1.size() < str2.size()) return LCS2(str2, str1);
    vector<int> dp(str2.size() + 1, 0);
    for (int i = 0; i != str1.size(); ++i) {
        int last = 0;
        for (int j = 0; j != str2.size(); ++j) {
            int tmp = dp[j + 1];
            dp[j + 1] = str1[i] == str2[j] ? last + 1 : max(dp[j + 1], dp[j]);
            last = tmp;
        }
    }
    return dp[str2.size()];
}

int main() {
    string str1 = "ABCDGHLQR", str2 = "AEDPHR";
    cout << LCS1(str1, str2) << endl;
    cout << LCS2(str1, str2) << endl;
    return 0;
}
