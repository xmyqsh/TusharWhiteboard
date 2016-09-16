/**
 * Date 09/15/2016
 * @author myqsh
 *
 * Write a program to find maximum sum rectangle in give 2D matrix.
 * Assume there is at least one positive number in the 2D matrix.
 *
 * Solution:
 * Keep temp array with size as number of rows. Start left and right from 0
 * and keep adding values for each row and maintain them in this temp array.
 * Run Kadane's algorithm to find max sum subarray in temp. Now increment right by
 * 1. When right reaches last column reset right to 1 and left to 1.
 *
 * Space complexity of this algorithm is O(row)
 * Time complexity of this algorithm is O(row*col*col)
 *
 * References
 * https://www.youtube.com/watch?v=yCQN096CwWM
 * http://www.geeksforgeeks.org/dynamic-programming-set-27-max-sum-rectangle-in-a-2d-matrix/
 */

#include "../tools/tools.h"

void kadane(vector<int>& result, const vector<int>& cache, int upper, int bottom) {
    int curSum = cache[0], left = 0;
    if (curSum > result[0]) {
        result[0] = curSum;
        result[1] = left;
        result[2] = 0;
        result[3] = upper;
        result[4] = bottom;
    }
    for (int i = 1; i != cache.size(); ++i) {
        if (curSum <= 0) {
            left = i;
            curSum = cache[i];
        } else curSum += cache[i];
        if (curSum > result[0]) {
            result[0] = curSum;
            result[1] = left;
            result[2] = i;
            result[3] = upper;
            result[4] = bottom;
        }
    }
}

vector<int> maxSum(const vector<vector<int> >& matrix) {
    vector<int> result(5, 0), cache(matrix[0].size());
    result[0] = INT_MIN;
    int lastSum = INT_MIN;
    for (int upper = 0; upper != matrix.size(); ++upper) {
        vector<int> cache(matrix[upper].begin(), matrix[upper].end());
        kadane(result, cache, upper, upper);
        int lastSum = result[0];
        for (int bottom = upper + 1; bottom != matrix.size(); ++bottom) {
            for (int col = 0; col != matrix[0].size(); ++col) cache[col] += matrix[bottom][col];
            kadane(result, cache, upper, bottom);
        }
    }
    return result;
}

int main() {
    vector<vector<int> > matrix = {{ 2,  1, -3, -4,  5},
                                   { 0,  6,  3,  4,  1},
                                   { 2, -2, -1,  4, -5},
                                   {-3,  3,  1,  0,  3}};
    printVec(maxSum(matrix));
    return 0;
}
