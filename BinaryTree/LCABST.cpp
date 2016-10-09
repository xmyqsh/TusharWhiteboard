// https://www.youtube.com/watch?v=TIoCCStdiFo
#include "../tools/tools.h"
#include "../tools/BinaryTree.h"

TreeNode* LCABST(TreeNode* root, int val1, int val2) {
    if (val1 > val2) return LCABST(root, val2, val1);
    if (root->val > val2) return LCABST(root->left, val1, val2);
    if (root->val < val1) return LCABST(root->right, val1, val2);
    return root;
}

int main() {
    BinaryTree* bt = new BinaryTree(10);
    bt->add(-5);
    bt->add(-6);
    bt->add(7);
    bt->add(6);
    bt->add(16);
    bt->add(18);
    cout << LCABST(bt->getRoot(), 6, -5)->val << endl;
    return 0;
}
