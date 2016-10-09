// binary search tree insertion
// https://www.youtube.com/watch?v=bmaeYtlO2OE
#ifndef BINARYTREE_H
#define BINARYTREE_H
#include "../tools/tools.h"

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int v) : val(v), left(NULL), right(NULL) {}
};

class BinaryTree {
public:
    BinaryTree(int val) { this->root = new TreeNode(val); }
    TreeNode* getRoot() const {
        return this->root;
    }
    void add(int val) {
        TreeNode* cur = root;
        while (1) {
            if (val < cur->val) {
                if (cur->left) cur = cur->left;
                else {
                  cur->left = new TreeNode(val);
                  break;
                }
            } else {
                if (cur->right) cur = cur->right;
                else {
                    cur->right = new TreeNode(val);
                    break;
                }
            }
        }
    }
    void printTree() {
        inOrderRecur(root);
        cout << endl;
    }
    static void inOrderRecur(TreeNode* root) {
        if (!root) return;
        inOrderRecur(root->left);
        cout << root->val << '\t';
        inOrderRecur(root->right);
    }
private:
    TreeNode* root;
};

#endif
