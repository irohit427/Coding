#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

typedef stack<TreeNode*> Stack;
Stack stk;
BSTIterator(TreeNode* root) {
    pushAll(root);
}
    
/** @return the next smallest number */
int next() {
    TreeNode* node = stk.top();
    stk.pop();
    pushAll(node->right);
    return node->val;
}

/** @return whether we have a next smallest number */
bool hasNext() {
    if (!stk.empty())   return true;
    return false;
}

void pushAll(TreeNode* node) {
    while(node != nullptr) {
        stk.push(node);
        node = node->left;
    }
}