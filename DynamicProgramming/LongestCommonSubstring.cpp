/**
 * Given two strings, find longest common substring between them.
 * https://www.youtube.com/watch?v=BysNXJHzCEs
 * http://en.wikipedia.org/wiki/Longest_common_substring_problem
 */

#include "../tools/tools.h"

int maxComLenDp(const string& str1, const string& str2) {
    if (str1.size() < str2.size()) return maxComLenDp(str2, str1);
    vector<int> dp(str2.size(), 0);
    int maxLen = 0;
    for (int i = 0; i != str1.size(); ++i) {
        int last = 0;
        for (int j = 0; j != str2.size(); ++j) {
            int tmp = dp[j];
            dp[j] = str1[i] == str2[j] ? last + 1 : 0;
            last = tmp;
            maxLen = max(maxLen, dp[j]);
        }
    }
    return maxLen;
}

int main() {
    string str1 = "abcdaf", str2 = "3bcdf";
    cout << maxComLenDp(str1, str2) << endl;
    return 0;
}
