/**
 * Date 09/27/2016
 * @author xmyqsh
 *
 * Video link - https://youtu.be/2xvJ41-hsoE
 *
 * Given a 2D matrix of 0s and 1s. Find largest rectangle of all 1s
 * in this matrix.
 *
 * Maintain a temp array of same size as number of columns.
 * Copy first row to this temp array and find largest rectangular area
 * for histogram. Then keep adding elements of next row to this temp
 * array if they are not zero. If they are zero then put zero there.
 * Every time calculate max area in histogram.
 *
 * Time complexity - O(rows*cols)
 * Space complexity - O(cols) - if number of cols is way higher than rows
 * then do this process for rows and not columns.
 *
 * References:
 * http://www.careercup.com/question?id=6299074475065344
 */

#include "../tools/tools.h"

int maxRectangular1s(const vector<vector<int> >& rectangular) {
    vector<int> height(rectangular[0].size(), 0); height.push_back(-1);
    int maxArea = 0;
    for (int i = 0; i != rectangular.size(); ++i) {
        for (int j = 0; j != rectangular[0].size(); ++j)
            height[j] = rectangular[i][j] == 1 ? height[j] + 1 : 0;
        stack<int> sk;
        for (int j = 0; j != height.size(); ) {
            if (sk.empty() || height[j] > sk.top()) {
                sk.push(j++);
            } else {
                int idx = sk.top();
                sk.pop();
                maxArea = max(maxArea, height[idx] * (sk.empty() ? j : j - sk.top() - 1));
            }
        }
    }
    return maxArea;
}

int main() {
    vector<vector<int> > rectangular = {{1,1,1,0},
                                      {1,1,1,1},
                                      {0,1,1,0},
                                      {0,1,1,1},
                                      {1,0,0,1},
                                      {1,1,1,1}};
    cout << maxRectangular1s(rectangular) << endl;
    return 0;
}
