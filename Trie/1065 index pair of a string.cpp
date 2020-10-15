#include<bits/stdc++.h>
using namespace std;

struct TrieNode{
    bool isEnd;
    vector<TrieNode*> children;
    TrieNode(): isEnd(false), children(vector<TrieNode*>(26, nullptr)) {}
};

TrieNode* root = new TrieNode();

vector<vector<int>> indexPairs(string text, vector<string>& words) {
    for(int i = 0; i < words.size(); i++) {
        insert(words[i]);
    }
    vector<vector<int>> result;
    for (int i = 0; i < text.length(); i++) {
        TrieNode* curr = root;
        for (int j = i; j < text.length(); j++) {
            curr = curr->children[text[j] - 'a'];
            if (curr != nullptr && curr->isEnd) 
                result.push_back({i, j});
            if (curr == nullptr)
                break;
        }
    }
    return result;
}

void insert(string word) {
    TrieNode* curr = root;
    for (int i = 0; i < word.length(); i++) {
        if (curr->children[word[i] - 'a'] == nullptr) {
            curr->children[word[i] - 'a'] = new TrieNode();
        }
        curr = curr->children[word[i] - 'a'];
    }
    curr->isEnd = true;
}