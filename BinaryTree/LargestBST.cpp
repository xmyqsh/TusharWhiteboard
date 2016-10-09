// https://www.youtube.com/watch?v=_SiwrPXG9-g
#include "../tools/tools.h"
#include "../tools/BinaryTree.h"

TreeNode* LargestBST(TreeNode* root, bool& isBST, int& size, int& minV, int& maxV) {
    bool leftIsBST, rightIsBST;
    int leftSize, rightSize, leftMinV, rightMinV, leftMaxV, rightMaxV;
    TreeNode *left, *right;
    if (root->left) left = LargestBST(root->left, leftIsBST, leftSize, leftMinV, leftMaxV);
    else { left = NULL; leftIsBST = true; leftSize = 0; }
    if (root->right) right = LargestBST(root->right, rightIsBST, rightSize, rightMinV, rightMaxV);
    else { right = NULL; rightIsBST = true; rightSize = 0; }
    if (leftIsBST && rightIsBST && (!left || left->val < root->val) && (!right || root->val < right->val)) {
        isBST = true; size = 1 + leftSize + rightSize; minV = left ? leftMinV: root->val; maxV = right ? rightMaxV : root->val;
    } else if (leftSize > rightSize) { root = left; size = leftSize; }
    else { root = right; size = rightSize; }
    return root;
}

int main() {
    BinaryTree* bt = new BinaryTree(25);
    TreeNode* root = bt->getRoot();
    root->left = new TreeNode(18); root->right = new TreeNode(50);
    root->left->left = new TreeNode(19); root->left->right = new TreeNode(20);
    root->right->left = new TreeNode(35); root->right->right = new TreeNode(60);
    root->left->left->right = new TreeNode(15);
    root->left->right->left = new TreeNode(18); root->left->right->right = new TreeNode(25);
    root->right->left->left = new TreeNode(20); root->right->left->right = new TreeNode(40);
    root->right->right->left = new TreeNode(55); root->right->right->right = new TreeNode(70);
    root->right->left->left->right = new TreeNode(25);
    cout << "Original BT:\t"; BinaryTree::inOrderRecur(bt->getRoot()); cout << endl;
    bool isBST; int size, minV, maxV;
    cout << "Largest BST:\t"; BinaryTree::inOrderRecur(LargestBST(bt->getRoot(), isBST, size, minV, maxV)); cout << endl;
    return 0;
}
