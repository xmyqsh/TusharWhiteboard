// https://www.youtube.com/watch?v=Jg4E4KZstFE
#include "../tools/tools.h"
#include "../tools/BinaryTree.h"

bool hasSumPath(TreeNode* root, int sum, vector<int>* result) {
    if (!root) return false;
    if (!root->left && !root->right) {
        if (root->val == sum) {
            result->push_back(root->val);
            return true;
        } else return false;
    }
    if (hasSumPath(root->left, sum - root->val, result) || hasSumPath(root->right, sum - root->val, result)) {
        result->push_back(root->val);
        return true;
    }
    return false;
}

int main() {
    BinaryTree* bt = new BinaryTree(10);
    bt->add(-5);
    bt->add(-6);
    bt->add(7);
    bt->add(6);
    bt->add(16);
    bt->add(18);
    vector<int> result;
    if (hasSumPath(bt->getRoot(), 18, &result)) {
        reverse(result.begin(), result.end());
        printVec(result);
    } else {
        cout << "NO PATH" << endl;
    }
    return 0;
}
