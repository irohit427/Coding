#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int maxDepth(TreeNode* root) {
    if (root == nullptr) return 0;
    int leftHeight = maxDepth(root->left);
    int rightHeight = maxDepth(root->right);
    return (leftHeight > rightHeight) ? leftHeight + 1: rightHeight + 1;
}
typedef queue<TreeNode*> Queue;
int maxDepth(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }

    Queue q;
    q.push(root);
    int height = 0;
    while (!q.empty()) {
        int levelCount = q.size();
        height += 1;
        while(levelCount--) {
            TreeNode* node = q.front();
            q.pop();
            if (node->left != nullptr)  q.push(node->left);
            if (node->right != nullptr) q.push(node->right);
        }
    }
    return height;
}