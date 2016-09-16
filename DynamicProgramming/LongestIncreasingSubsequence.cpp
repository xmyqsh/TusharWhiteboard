/**
 * Date 16/09/2016
 * @author tusroy
 *
 * Youtube link - https://youtu.be/CE2b_-XfVDk
 *
 * Find a subsequence in given array in which the subsequence's elements are
 * in sorted order, lowest to highest, and in which the subsequence is as long as possible
 *
 * Solution :
 * Dynamic Programming is used to solve this question. DP equation is
 * if(arr[i] > arr[j]) { T[i] = max(T[i], T[j] + 1 }
 *
 * Time complexity is O(n^2), further optimize to O(n*log2(n)).
 * Space complexity is O(n)
 *
 * Reference
 * http://en.wikipedia.org/wiki/Longest_increasing_subsequence
 * http://www.geeksforgeeks.org/dynamic-programming-set-3-longest-increasing-subsequence/
 */

#include "../tools/tools.h"

// DP1  O(n^2)
int LISDp1(const vector<int>& vec) {
    vector<int> dp(vec.size(), 1);
    for (int i = 1; i != vec.size(); ++i)
        for (int j = i - 1; j >= 0; --j)
            if (vec[j] < vec[i]) dp[i] = max(dp[i], 1 + dp[j]);
    return dp[vec.size() - 1];
}

// DP2 O(n*log2(n))
int my_lower_bound(const vector<int>& vec, int val) {
    int b = 0, e = vec.size() - 1;
    while (b <= e) {
        const int mid = b + (e - b) / 2;
        if (vec[mid] < val) b = mid + 1;
        else e = mid - 1;
    }
    return b;
}
int LISDp2(const vector<int>& vec) {
    vector<int> cache; cache.reserve(vec.size());
    cache.push_back(vec[0]);
    for (int i = 1, idx; i != vec.size(); ++i) {
        if ((idx = my_lower_bound(cache, vec[i])) == cache.size()) cache.push_back(vec[i]);
        else cache[idx] = vec[i];
    }
    return cache.size();
}

int main() {
    vector<int> vec = {23,10,22,5,33,8,9,21,50,41,60,80,99,22,23,24,25,26,27};
    cout << LISDp1(vec) << endl;
    cout << LISDp2(vec) << endl;
    return 0;
}
