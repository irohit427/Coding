#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

enum State {None, Covered, Camera};
int minCameraCover(TreeNode* root) {
    int camera = 0;
    if (dfs(root, camera) == None)
        camera += 1;
    return camera;
}

State dfs(TreeNode* root, int& camera) {
    if (root == nullptr)
        return Covered;
    
    State left = dfs(root->left, camera);
    State right = dfs(root->right, camera);

    if (left == None || right == None) {
        camera++;
        return Camera;
    }

    if (left == Camera || right == Camera) {
        return Covered;
    }
    return None;
}
