// https://www.youtube.com/watch?v=9PHkM0Jri_4
// https://www.youtube.com/watch?v=7uG0gLDbhsI
// https://www.youtube.com/watch?v=D2bIbWGgvzI
#include "../tools/tools.h"
#include "../tools/BinaryTree.h"

void LevelOrderRecur(TreeNode* root, vector<vector<int> >& result, int level) {
    if (!root) return;
    if (result.size() == level) result.push_back(vector<int>());
    result[level].push_back(root->val);
    LevelOrderRecur(root->left, result, level + 1);
    LevelOrderRecur(root->right, result, level + 1);
}

void LevelOrderIterative(TreeNode* root) {
    queue<TreeNode*> q;
    if (root) q.push(root);
    while (!q.empty()) {
        root = q.front(); q.pop();
        cout << root->val << '\t';
        if (root->left) q.push(root->left);
        if (root->right) q.push(root->right);
    }
}

void LevelByLevelOrderIterative(TreeNode* root) {
    queue<TreeNode*> q1, q2;
    if (root) q2.push(root);
    while (!q2.empty()) {
        swap(q1, q2);
        while (!q1.empty()) {
            root = q1.front(); q1.pop();
            cout << root->val << '\t';
            if (root->left) q2.push(root->left);
            if (root->right) q2.push(root->right);
        }
        cout << endl;
    }
}

void ReverseLevelOrderIterative(TreeNode* root) {
    queue<TreeNode*> q;
    stack<int> sk;
    if (root) q.push(root);
    while (!q.empty()) {
        root = q.front(); q.pop();
        sk.push(root->val);
        if (root->right) q.push(root->right);
        if (root->left) q.push(root->left);
    }
    while (!sk.empty()) {
        cout << sk.top() << '\t';
        sk.pop();
    }
}

int main() {
    BinaryTree* bt = new BinaryTree(10);
    bt->add(-5);
    bt->add(-6);
    bt->add(7);
    bt->add(6);
    bt->add(16);
    bt->add(18);
    vector<vector<int> > result;
    LevelOrderRecur(bt->getRoot(), result, 0);
    cout << "LevelOrderRecur:" << endl;
    for (auto row : result) for (auto elem : row) cout << elem << '\t'; cout << endl;
    cout << "LevelOrderIterative:" << endl;
    LevelOrderIterative(bt->getRoot()); cout << endl;
    cout << "LevelByLevelOrderRecur:" << endl;
    printMat(result);
    cout << "LevelByLevelOrderIterative:" << endl;
    LevelByLevelOrderIterative(bt->getRoot());
    cout << "ReverseLevelOrderRecur:" << endl;
    for (auto rIterRow = result.rbegin(); rIterRow != result.rend(); ++rIterRow)
        for (auto elem : *rIterRow) cout << elem << '\t'; cout << endl;
    cout << "ReverseLevelOrderIterative:" << endl;
    ReverseLevelOrderIterative(bt->getRoot()); cout << endl;
    return 0;
}
