// https://www.youtube.com/watch?v=ySDDslG8wws
#include "../tools/tools.h"
#include "../tools/BinaryTree.h"

bool sameTree(TreeNode* root1, TreeNode* root2) {
    if (!root1 && !root2) return true;
    if (!root1 || !root2) return false;
    return root1->val == root2->val &&
            sameTree(root1->left, root2->left) &&
            sameTree(root1->right, root2->right);
}

int main() {
    BinaryTree* bt1 = new BinaryTree(10);
    bt1->add(-5);
    bt1->add(-6);
    bt1->add(7);
    bt1->add(6);
    bt1->add(16);
    bt1->add(18);
    BinaryTree* bt2 = new BinaryTree(10);
    bt2->add(-5);
    bt2->add(-6);
    bt2->add(7);
    bt2->add(6);
    bt2->add(16);
    bt2->add(18);
    cout << sameTree(bt1->getRoot(), bt2->getRoot()) << endl;
    bt2->add(0);
    cout << sameTree(bt1->getRoot(), bt2->getRoot()) << endl;
    return 0;
}
