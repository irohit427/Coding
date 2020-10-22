#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    return treeBuilder(0, 0, inorder.size() - 1, preorder, inorder);
}

TreeNode* treeBuilder(int rootIndex, int inorderStart, int inorderEnd, vector<int>& preorder, vector<int>& inorder) {
    if (rootIndex > preorder.size() - 1 || inorderStart > inorderEnd) return nullptr;
    TreeNode* root = new TreeNode(preorder[rootIndex]);
    int inorderIndex;
    for (int i = inorderStart; i <= inorderEnd; i++) {
        if (preorder[rootIndex] == inorder[i]) {
            inorderIndex = i;
            break;
        }
    }
    root->left = treeBuilder(rootIndex + 1, inorderStart, inorderIndex - 1, preorder, inorder);
    root->right = treeBuilder(rootIndex + inorderIndex - inorderStart + 1, inorderIndex + 1, inorderEnd, preorder, inorder);
    return root;
}

/**
 * Using Stack
 */
