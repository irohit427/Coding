#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

typedef queue<TreeNode*> Queue; 
vector<vector<int>> levelOrder(TreeNode* root) {
    if (root == nullptr)
        return {};
    
    Queue q;
    vector<vector<int>> result;

    q.push(root);
    
    while(!q.empty()) {
        vector<int> v;
        int n = q.size();
        for (int i = 0; i < n; i++) {
            TreeNode* node = q.front();
            q.pop();
            v.push_back(node->val);

            if (node->left != nullptr) 
                q.push(node->left);
            
            if (node->right != nullptr)
                q.push(node->right);
        }
        result.push_back(v);
    }
    return result;
}