// https://www.youtube.com/watch?v=13m9ZCB8gjw
#include "../tools/tools.h"
#include "../tools/BinaryTree.h"

TreeNode* LCABT(TreeNode* root, int val1, int val2) {
    if (!root || root->val == val1 || root->val == val2) return root;
    TreeNode* left = LCABT(root->left, val1, val2);
    TreeNode* right = LCABT(root->right, val1, val2);
    if (left && right) return root;
    if (left) return left;
    return right;
}

int main() {
    BinaryTree* bt = new BinaryTree(10);
    bt->add(-5);
    bt->add(-6);
    bt->add(7);
    bt->add(6);
    bt->add(16);
    bt->add(18);
    cout << LCABT(bt->getRoot(), 6, -5)->val << endl;
    cout << LCABT(bt->getRoot(), 6, 18)->val << endl;
    return 0;
}
