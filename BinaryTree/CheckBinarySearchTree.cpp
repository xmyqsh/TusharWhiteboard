// https://www.youtube.com/watch?v=MILxfAbIhrE
#include "../tools/tools.h"
#include "../tools/BinaryTree.h"

bool check(TreeNode* root) {
    if (!root) return true;
    if (root->left && root->left->val >= root->val) return false;
    if (root->right && root->right->val <= root->val) return false;
    return check(root->left) && check(root->right);
}

int main() {
    BinaryTree* bt = new BinaryTree(10);
    bt->add(-5);
    bt->add(-6);
    bt->add(7);
    bt->add(6);
    bt->add(16);
    bt->add(18);
    cout << check(bt->getRoot()) << endl;
    return 0;
}
