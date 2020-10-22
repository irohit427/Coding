#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int distributeCoins(TreeNode* root) {
    int moves = 0;
    calculateMoves(root, moves);
    return moves;
}

int calculateMoves(TreeNode* root, int& moves) {
    if (root == nullptr)
        return 0;
    int left = calculateMoves(root->left, moves);
    int right = calculateMoves(root->right, moves);

    moves += abs(left) + abs(right);
    return root->val + left + right - 1;
}