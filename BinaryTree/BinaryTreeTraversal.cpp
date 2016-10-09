// https://www.youtube.com/watch?v=ZM-sV9zQPEs
// https://www.youtube.com/watch?v=qT65HltK2uE
// https://www.youtube.com/watch?v=elQcrJrfObg
// https://www.youtube.com/watch?v=nzmtCFNae9k
// https://www.youtube.com/watch?v=xLQKdq0Ffjg
// https://www.youtube.com/watch?v=wGXB9OWhPTg
#include "../tools/tools.h"
#include "../tools/BinaryTree.h"

void preOrderRecur(TreeNode* root) {
    if (!root) return;
    cout << root->val << '\t';
    preOrderRecur(root->left);
    preOrderRecur(root->right);
}

void inOrderRecur(TreeNode* root) {
    if (!root) return;
    inOrderRecur(root->left);
    cout << root->val << '\t';
    inOrderRecur(root->right);
}

void postOrderRecur(TreeNode* root) {
    if (!root) return;
    postOrderRecur(root->left);
    postOrderRecur(root->right);
    cout << root->val << '\t';
}

void preOrderIterative(TreeNode* root) {
    stack<TreeNode*> sk;
    if (root) sk.push(root);
    while (!sk.empty()) {
        root = sk.top(); sk.pop();
        cout << root->val << '\t';
        if (root->right) sk.push(root->right);
        if (root->left) sk.push(root->left);
    }
}

void inOrderIterative(TreeNode* root) {
    stack<TreeNode*> sk;
    while (root || !sk.empty()) {
        if (root) {
            sk.push(root);
            root = root->left;
        } else {
            root = sk.top(); sk.pop();
            cout << root->val << '\t';
            root = root->right;
        }
    }
}

void postOrderIterative(TreeNode* root) {
    stack<TreeNode*> sk1;
    stack<int> sk2;
    if (root) sk1.push(root);
    while (!sk1.empty()) {
        root = sk1.top(); sk1.pop();
        sk2.push(root->val);
        if (root->left) sk1.push(root->left);
        if (root->right) sk1.push(root->right);
    }
    while (!sk2.empty()) {
        cout << sk2.top() << '\t';
        sk2.pop();
    }
}

void postOrderIterativeWithOneStack(TreeNode* root) {
    stack<TreeNode*> sk;
    TreeNode *p = root, *q = NULL;
    do {
        while (p) {
            sk.push(p);
            p = p->left;
        }
        q = NULL;
        while (!sk.empty()) {
            p = sk.top();
            if (p->right == q) {
                sk.pop();
                cout << p->val << '\t';
                q = p;
            } else {
                p = p->right;
                break;
            }
        }
    } while (!sk.empty());
}

void preOrderMorris(TreeNode* root) {
    while (root) {
        if (!root->left) {
            cout << root->val << '\t';
            root = root->right;
        } else {
            TreeNode* preNode = root->left;
            while (preNode->right && preNode->right != root) preNode = preNode->right;
            if (!preNode->right) {
                preNode->right = root;
                cout << root->val << '\t';
                root = root->left;
            } else {
                preNode->right = NULL;
                root = root->right;
            }
        }
    }
}

void inOrderMorris(TreeNode* root) {
    while (root) {
        if (!root->left) {
            cout << root->val << '\t';
            root = root->right;
        } else {
            TreeNode* preNode = root->left;
            while (preNode->right && preNode->right != root) preNode = preNode->right;
            if (!preNode->right) {
                preNode->right = root;
                root = root->left;
            } else {
                preNode->right = NULL;
                cout << root->val << '\t';
                root = root->right;
            }
        }
    }
}

int main() {
    BinaryTree* bt = new BinaryTree(10);
    bt->add(-5);
    bt->add(-6);
    bt->add(7);
    bt->add(6);
    bt->add(16);
    bt->add(18);
    cout << "preOrderRecur: \t\t\t"; preOrderRecur(bt->getRoot()); cout << endl;
    cout << "inOrderRecur: \t\t\t"; inOrderRecur(bt->getRoot()); cout << endl;
    cout << "postOrderRecur: \t\t"; postOrderRecur(bt->getRoot()); cout << endl;
    cout << "preOrderIterative: \t\t"; preOrderIterative(bt->getRoot()); cout << endl;
    cout << "inOrderIterative: \t\t"; inOrderIterative(bt->getRoot()); cout << endl;
    cout << "postOrderIterative: \t\t"; postOrderIterative(bt->getRoot()); cout << endl;
    cout << "postOrderIterativeWithOneStack: "; postOrderIterativeWithOneStack(bt->getRoot()); cout << endl;
    cout << "preOrderMorris: \t\t"; preOrderMorris(bt->getRoot()); cout << endl;
    cout << "inOrderMorris: \t\t\t"; inOrderMorris(bt->getRoot()); cout << endl;
    return 0;
}
