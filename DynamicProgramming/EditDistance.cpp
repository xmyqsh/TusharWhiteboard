/**
 * Date 16/09/2016
 * @author xmyqsh
 *
 * Given two strings how many minimum edits(update, delete or add) is needed to convert one string to another
 *
 * Time complexity is O(m*n)
 * Space complexity is O(m*n)
 *
 * References:
 * https://www.youtube.com/watch?v=We3YDTzNXEk
 * http://www.geeksforgeeks.org/dynamic-programming-set-5-edit-distance/
 * https://en.wikipedia.org/wiki/Edit_distance
 */

#include "../tools/tools.h"

int EditDistanceDp1(const string& str1, const string& str2) {
    vector<vector<int> > dp(str1.size() + 1, vector<int>(str2.size() + 1, max(str1.size(), str2.size())));
    for (int i = 0; i <= str1.size(); ++i) {
        for (int j = 0; j <= str2.size(); ++j) {
            if (i == 0) dp[i][j] = j;
            else if (j == 0) dp[i][j] = i;
            else dp[i][j] = str1[i - 1] == str2[j - 1] ? dp[i - 1][j - 1] : 1 + min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]));
        }
    }
    return dp[str1.size()][str2.size()];
}

int EditDistanceDp2(const string& str1, const string& str2) {
    if (str1.size() < str2.size()) return EditDistanceDp2(str2, str1);
    vector<int> dp(str2.size(), max(str1.size(), str2.size()));
    for (int i = 0; i != str1.size(); ++i) {
        int last = i;
        for (int j = 0; j != str2.size(); ++j) {
            int tmp = dp[j];
            dp[j] = str1[i] == str2[j] ? last : 1 + min(last, min(dp[j], dp[j - 1]));
            last = tmp;
        }
    }
    return dp[str2.size() - 1];
}

int main() {
    string str1 = "azced", str2 = "abcdef";
    cout << EditDistanceDp1(str1, str2) << endl;
    cout << EditDistanceDp2(str1, str2) << endl;
    return 0;
}
