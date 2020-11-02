#include<bits/stdc++.h>
using namespace std;

struct TrieNode {
    int val;
    vector<TrieNode*> bits;
    TrieNode(): val(0), bits(vector<TrieNode*>(2, nullptr)) {}
};

TrieNode* root = new TrieNode();

void insertTrie(int num) {
    TrieNode* curr = root;
    for (int i = 31; i >= 0; i--) {
        bool currentBit = (num & (1 << i));
        if (curr->bits[currentBit] == nullptr) {
            curr->bits[currentBit] = new TrieNode();
        }
        curr = curr->bits[currentBit];
    }
    curr->val = num;
}

int checkTrie(int num) {
    TrieNode* curr = root;
    for (int i = 31; i >= 0; i--) {
        bool currentBit = (num & (1 << i));
        if (curr->bits[1-currentBit] != nullptr) {
            curr = curr->bits[1-currentBit];
        } else if (curr->bits[currentBit] != nullptr) {
            curr = curr->bits[currentBit];
        }
    }
    return curr->val;
}

int findMaximumXOR(vector<int>& nums) {
    if (nums.size() < 2) return 0;
    int ans = 0, n = nums.size();
    insertTrie(nums[0]);

    for (int i = 1; i < n; i++) {
        ans = max(ans, nums[i] ^ checkTrie(nums[i]));
        insertTrie(nums[i]);
    }
    return ans;
}