#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

typedef queue<TreeNode*> Queue;
vector<int> rightSideView(TreeNode* root) {
    if (root == nullptr)
        return {};
    vector<int> result;
    Queue q;
    q.push(root);
    int n;
    while(q.empty()) {
        n = q.size();
        for (int i = 0; i < n; i++) {
            TreeNode* curr = q.front();
            q.pop();
            if (i == n-1) {
                result.push_back(curr->val);
            }
            if (curr->left != nullptr)
                q.push(curr->left);
            
            if (curr->right != nullptr)
                q.push(curr->right);
        }
    }
    return result;
}