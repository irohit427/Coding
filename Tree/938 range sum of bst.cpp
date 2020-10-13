#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int rangeSumBST(TreeNode* root, int L, int R) {
    int sum = 0;
    dfs(root, L, R, sum);
    return sum;    
}

void dfs(TreeNode* root, int L, int R, int& sum) {
    if (root != nullptr) {
        if (root-> val >= L && root->val <= R)
            sum += root->val;
        
        if (root->val > L) 
            dfs(root->left, L, R, sum);
        
        if (root->val < R)
            dfs(root->right, L, R, sum);
    }
}