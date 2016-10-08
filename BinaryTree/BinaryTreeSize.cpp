// https://www.youtube.com/watch?v=NA8B84DZYSA
#include "../tools/tools.h"
#include "../tools/BinaryTree.h"

int size(TreeNode* root) {
    if (!root) return 0;
    return 1 + size(root->left) + size(root->right);
}

int main() {
    BinaryTree* bt = new BinaryTree(10);
    bt->add(-5);
    bt->add(-6);
    bt->add(7);
    bt->add(6);
    bt->add(16);
    bt->add(18);
    cout << size(bt->getRoot()) << endl;
    return 0;
}
