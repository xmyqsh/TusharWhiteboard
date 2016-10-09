// https://www.youtube.com/watch?v=9PHkM0Jri_4
// https://www.youtube.com/watch?v=7uG0gLDbhsI
// https://www.youtube.com/watch?v=D2bIbWGgvzI
// https://www.youtube.com/watch?v=vjt5Y6-1KsQ
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

void SpiralOrderIterative(TreeNode* root) {
    stack<TreeNode*> sk1, sk2;
    if (root) sk2.push(root);
    while (!sk1.empty() || !sk2.empty()) {
        if (!sk1.empty()) {
            while (!sk1.empty()) {
                root = sk1.top(); sk1.pop();
                cout << root->val << '\t';
                if (root->right) sk2.push(root->right);
                if (root->left) sk2.push(root->left);
            }
        } else {
            while (!sk2.empty()) {
                root = sk2.top(); sk2.pop();
                cout << root->val << '\t';
                if (root->left) sk1.push(root->left);
                if (root->right) sk1.push(root->right);
            }
        }
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
    cout << "SpiralOrderRecur:" << endl;
    for (int i = 1; i < result.size(); i += 2) reverse(result[i].begin(), result[i].end());
    for (auto row : result) for (auto elem : row) cout << elem << '\t'; cout << endl;
    cout << "SpiralOrderIterative:" << endl;
    SpiralOrderIterative(bt->getRoot()); cout << endl;
    return 0;
}
