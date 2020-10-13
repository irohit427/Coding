#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* invertTree(TreeNode* root) {
    if (root == nullptr)
        return nullptr;
    TreeNode* left = invertTree(root->left);
    TreeNode* right = invertTree(root->right);
    root->left = right;
    root->right = left;
    return root;
}

typedef queue<TreeNode*> Queue;
TreeNode* invertTree(TreeNode* root) {
    if (root == nullptr)
        return nullptr;
    Queue q;
    q.push(root);
    while(!q.empty()) {
        TreeNode* current = q.front();
        q.pop();
        swap(current->left, current->right);
        if (current->left != nullptr) q.push(current->left);
        if (current->right != nullptr) q.push(current->right);
    }
    return root;
}