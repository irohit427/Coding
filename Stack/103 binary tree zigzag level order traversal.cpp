#include<bits/stdc++.h>
using namespace std;


 
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 

typedef stack<TreeNode*> Stack;
/** Using Stack*/
vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    if (root == nullptr) return {};
    vector<vector<int>> ans;
    Stack stk_1, stk_2;
    bool leftFirst = true;
    stk_1.push(root);
    vector<int> temp;
    while(!stk_1.empty()) {
        int n = stk_1.size();
        for (int i = 0; i < n; i++) {
            TreeNode* curr = stk_1.top();
            if (leftFirst) {
                if (curr->left != nullptr) stk_2.push(curr->left);
                if (curr->right != nullptr) stk_2.push(curr->right);
            } else {
                if (curr->right != nullptr) stk_2.push(curr->right);
                if (curr->left != nullptr) stk_2.push(curr->left);
            }
            temp.push_back(curr->val);
            stk_1.pop();
        }
        swap(stk_1, stk_2);
        ans.push_back(temp);
        temp.clear();
        leftFirst = !leftFirst;
    }
    return ans;
}

/** Using Queue */

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    
}