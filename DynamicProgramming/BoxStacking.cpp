/**
 * Date 09/27/2016
 * @author xmyqsh
 *
 * Given different dimensions and unlimited supply of boxes for each dimension, stack boxes
 * on top of each other such that it has maximum height but with caveat that length and width
 * of box on top should be strictly less than length and width of box under it. You can
 * rotate boxes as you like.
 *
 * 1) Create all rotations of boxes such that length is always greater or equal to width
 * 2) Sort boxes by base area in non increasing order (length * width). This is because box
 * with more area will never ever go on top of box with less area.
 * 3) Take T[] and result[] array of same size as total boxes after all rotations are done
 * 4) Apply longest increasing subsequence type of algorithm to get max height.
 *
 * If n number of dimensions are given total boxes after rotation will be 3n.
 * So space complexity is O(n)
 * Time complexity - O(nlogn) to sort boxes. O(n^2) to apply DP on it So really O(n^2)
 *
 * References
 * https://www.youtube.com/watch?v=9mod_xRB-O0
 * http://www.geeksforgeeks.org/dynamic-programming-set-21-box-stacking-problem/
 * http://people.cs.clemson.edu/~bcdean/dp_practice/
 */

#include "../tools/tools.h"

void generateBoxs(vector<vector<int> >& boxs) {
    vector<vector<int> > genBoxs(boxs.size() * 3);
    for (int i = 0; i != boxs.size(); ++i) {
        genBoxs[3 * i] = {boxs[i][2], boxs[i][1], boxs[i][0]};
        genBoxs[3 * i + 1] = {boxs[i][2], boxs[i][0], boxs[i][1]};
        genBoxs[3 * i + 2] = {boxs[i][1], boxs[i][0], boxs[i][2]};
    }
    swap(genBoxs, boxs);
}

int maxHeightDp(const vector<vector<int> >& boxs) {
    vector<int> dp(boxs.size());
    for (int i = 0; i != boxs.size(); ++i) dp[i] = boxs[i][2];
    int maxHeight = dp[0];
    for (int i = 1; i != boxs.size(); ++i) {
        for (int j = 0; j < i; ++j)
            if (boxs[j][0] > boxs[i][0] && boxs[j][1] > boxs[i][1] && dp[j] + boxs[i][2] > dp[i])
                dp[i] = dp[j] + boxs[i][2];
        maxHeight = max(maxHeight, dp[i]);
    }
    return maxHeight;
}

int main() {
    vector<vector<int> > boxs = {{3,2,5}, {1,2,4}};
    for (int i = 0; i != boxs.size(); ++i) sort(boxs[i].begin(), boxs[i].end());
    generateBoxs(boxs);
    sort(boxs.begin(), boxs.end(), [](const vector<int>& box1, const vector<int>& box2) {
            return box1[0] * box1[1] > box2[0] * box2[1];
        });
    cout << maxHeightDp(boxs) << endl;
    return 0;
}
