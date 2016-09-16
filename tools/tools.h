#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

void printVec(const vector<int>& vec) {
    for (int i = 0; i != vec.size(); ++i)
        cout << vec[i] << '\t';
    cout << endl;
}

void printMat(const vector<vector<int> >& mat) {
    for (int i = 0; i != mat.size(); ++i) {
        for (int j = 0; j != mat[0].size(); ++j)
            cout << mat[i][j] << '\t';
        cout << endl;
    }
}
