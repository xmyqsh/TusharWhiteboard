/**
 * Given some number of floors and some number of eggs, what is the minimum number of attempts it will take
 * to find out from which floor egg will break.
 * https://www.youtube.com/watch?v=3hcaVyX00_4
 * http://www.geeksforgeeks.org/dynamic-programming-set-11-egg-dropping-puzzle/
 */

#include "../tools/tools.h"

int calcMemorization(int eggs, int floors, vector<vector<int> >& cache) {
    if (floors == 0) return 0;
    if (eggs == 1) return floors;
    if (cache[eggs][floors]) return cache[eggs][floors];
    cache[eggs][floors] = INT_MAX;
    for (int k = 1; k <= floors; ++k)
        cache[eggs][floors] = min(cache[eggs][floors],
                                  max(calcMemorization(eggs - 1, k - 1, cache),
                                      calcMemorization(eggs, floors - k, cache)));
    cache[eggs][floors] += 1;
    return cache[eggs][floors];
}

int calcDp1(int eggs, int floors) {
    vector<vector<int> > dp(eggs + 1, vector<int>(floors + 1, 0));
    for (int j = 1; j <= floors; ++j) dp[1][j] = j;
    for (int i = 2; i <= eggs; ++i) {
        for (int j = 1; j <= floors; ++j) {
            dp[i][j] = INT_MAX;
            for (int k = 1; k <= j; ++k)
                dp[i][j] = min(dp[i][j], max(dp[i - 1][k - 1], dp[i][j - k]));
            dp[i][j] += 1;
        }
    }
    return dp[eggs][floors];
}

int calcDp2(int eggs, int floors) {
    vector<int> dp(floors + 1, 0);
    for (int j = 1; j <= floors; ++j) dp[j] = j;
    for (int i = 2; i <= eggs; ++i) {
        vector<int> dpBk(dp);
        for (int j = 1; j <= floors; ++j) {
            dp[j] = INT_MAX;
            for (int k = 1; k <= j; ++k)
                dp[j] = min(dp[j], max(dpBk[k - 1], dp[j - k]));
            dp[j] += 1;
        }
    }
    return dp[floors];
}

int main() {
    int eggs = 2, floors = 6;
    vector<vector<int> > cache(eggs + 1, vector<int>(floors + 1, 0));
    cout << calcMemorization(eggs, floors, cache) << endl;
    cout << calcDp1(eggs, floors) << endl;
    cout << calcDp2(eggs, floors) << endl;
    return 0;
}
