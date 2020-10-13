#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
    if (nums.size() == 0)
        return nullptr;
    int maxIndex = maximumIndex(nums);
    TreeNode* root = new TreeNode(nums[maxIndex]);
    vector<int> left(nums.begin(), nums.begin() + maxIndex);
    vector<int> right(nums.begin() + maxIndex + 1, nums.end());
    root->left = constructMaximumBinaryTree(left);
    root->right = constructMaximumBinaryTree(right);
    return root;
}

int maximumIndex(vector<int> nums) {
    pair<int, int> maxNum = {INT_MIN, -1};
    for (int i = 0;i < nums.size(); i++) {
        if (nums[i] > maxNum.first) {
            maxNum.first = nums[i];
            maxNum.second = i;
        }
    }
    return maxNum.second;
}