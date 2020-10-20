#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

string serialize(TreeNode* root) {
    if (root == nullptr)
        return "null";
    
    return to_string(root->val) + " " + serialize(root->left) + " " + serialize(root->right);
}

TreeNode* deserialize(string data) {
    stringstream str(data);
    return deserialize(str);
}

TreeNode* deserialize(stringstream& data) {
    string str;
    if (!(data >> str) || str == "nullptr")
        return nullptr;
    TreeNode* node = new TreeNode(stoi(str));
    node->left = deserialize(data);
    node->right = deserialize(data);
    return node;
}