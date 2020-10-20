#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void flatten(TreeNode* root) {
    if (!root) return;
    vector<TreeNode*> nodes;
    preOrderTraversal(root, nodes);
    int n = nodes.size();
    for (int i = 0; i < n - 1; i++) {
        nodes[i]->left = nullptr;
        nodes[i]->right = nodes[i+1];
    }
    nodes[n-1]->left = nullptr, nodes[n-1]->right = nullptr;
}

void preOrderTraversal(TreeNode* root, vector<TreeNode*>& nodes) {
    if (!root)
        return ;
    nodes.push_back(root);
    preOrderTraversal(root->left, nodes);
    preOrderTraversal(root->right, nodes);
}