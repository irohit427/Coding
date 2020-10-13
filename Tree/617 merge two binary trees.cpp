#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
    if (t1 == nullptr)  return t2;
    if (t2 == nullptr)  return t1;

    t1->val = t1->val + t2->val;
    t1->left = mergeTrees(t1->left, t2->left);
    t1->right = mergeTrees(t1->right, t2->right);
    return t1;
}

typedef stack<pair<TreeNode*, TreeNode*>> Stack;
TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
    if (t1 == nullptr)  return t2;
    if (t2 == nullptr)  return t1;

    Stack stk;
    stk.push({t1, t2});
    while(!stk.empty()) {
        pair<TreeNode*, TreeNode*> top = stk.top();
        stk.pop();
        if (top.first == nullptr || top.second == nullptr)
            continue;
        top.first->val += top.second->val;
        if (top.first->left == nullptr) {
            top.first->left = top.second->left;
        } else {
            stk.push({top.first->left, top.second->left});
        }

        if (top.first->right == nullptr) {
            top.first->right = top.second->right;
        } else {
            stk.push({top.first->right, top.second->right});
        }
    }
    return t1;
}