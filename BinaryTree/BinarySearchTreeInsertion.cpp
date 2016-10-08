// https://www.youtube.com/watch?v=bmaeYtlO2OE
#include "../tools/tools.h"
#include "../tools/BinaryTree.h"

bool insertRecur(TreeNode*& root, int val) {
    if (!root) root = new TreeNode(val);
    else if (val < root->val) insertRecur(root->left, val);
    else if (val > root->val) insertRecur(root->right, val);
    else return false;
    return true;
}

bool insertIterative(TreeNode* root, int val) {
    while (1) {
        if (val < root->val) {
            if (root->left) root = root->left;
            else {
                root->left = new TreeNode(val);
                break;
            }
        } else if (val > root->val) {
            if (root->right) root = root->right;
            else {
                root->right = new TreeNode(val);
                break;
            }
        } else return false;
    }
    return true;
}

int main() {
    BinaryTree* bt = new BinaryTree(10);
    TreeNode* root = bt->getRoot();
    insertRecur(root, -5);
    insertRecur(root, -6);
    insertRecur(root, 7);
    insertRecur(root, 6);
    insertRecur(root, 16);
    insertRecur(root, 18);
    bt->printTree();

    BinaryTree* bt1 = new BinaryTree(10);
    TreeNode* root1 = bt1->getRoot();
    insertIterative(root1 , -5);
    insertIterative(root1 , -6);
    insertIterative(root1 , 7);
    insertIterative(root1 , 6);
    insertIterative(root1 , 16);
    insertIterative(root1 , 18);
    bt1->printTree();
    return 0;
}
