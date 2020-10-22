#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

typedef stack<TreeNode*> Stack;
vector<int> inorderTraveral(TreeNode* root) {
    if (root == nullptr)
        return {};

    Stack stk;
    TreeNode* node = root;
    vector<int> result;
    while(node || !stk.empty()) {
        while(node) {
            stk.push(node);
            node = node->left;
        }
        node = stk.top();
        stk.pop();
        result.push_back(node->val);
        node = node->right;
    }
    return result;
}