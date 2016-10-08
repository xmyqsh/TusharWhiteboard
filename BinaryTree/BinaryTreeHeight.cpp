// https://www.youtube.com/watch?v=_SiwrPXG9-g
#include "../tools/tools.h"
#include "../tools/BinaryTree.h"

int height(TreeNode* root) {
    if (!root) return 0;
    return 1 + max(height(root->left), height(root->right));
}

int main() {
    BinaryTree* bt = new BinaryTree(10);
    bt->add(-5);
    bt->add(-6);
    bt->add(7);
    bt->add(6);
    bt->add(16);
    bt->add(18);
    cout << height(bt->getRoot()) << endl;
    return 0;
}
