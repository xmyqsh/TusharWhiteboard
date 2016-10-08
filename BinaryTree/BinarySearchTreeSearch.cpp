// https://www.youtube.com/watch?v=zm83jPHZ-jA
#include "../tools/tools.h"
#include "../tools/BinaryTree.h"

TreeNode* search(TreeNode* root, int val) {
    TreeNode* result = NULL;
    while (root) {
        if (val < root->val) root = root->left;
        else if (val > root->val) root = root->right;
        else { result = root; break; }
    }
    return result;
}

int main() {
    BinaryTree* bt = new BinaryTree(10);
    bt->add(-5);
    bt->add(-6);
    bt->add(7);
    bt->add(6);
    bt->add(16);
    bt->add(18);
    cout << (NULL != search(bt->getRoot(), 0)) << endl;
    cout << (NULL != search(bt->getRoot(), 6)) << endl;
    cout << (NULL != search(bt->getRoot(), 10)) << endl;
    cout << (NULL != search(bt->getRoot(), -5)) << endl;
    return 0;
}
