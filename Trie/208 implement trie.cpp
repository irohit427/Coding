#include<bits/stdc++.h>
using namespace std;

struct TrieNode {
    bool isEnd;
    vector<TrieNode*> children;
    TrieNode(): isEnd(false), children(vector<TrieNode*> (26, nullptr)) {}
};

TrieNode* root;
Trie() {
    root = new TrieNode();
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

bool search(string word) {
    return find(word, true);
}

bool startsWith(string prefix) {
    return find(prefix, false);
}

bool find(string s, bool exactMatch) {
    TrieNode* curr = root;

    for (int i = 0; i < s.length(); i++) {
        if (curr->children[s[i] - 'a'] == nullptr)
            return false;
        curr = curr->children[s[i] - 'a'];
    }
    if (exactMatch) {
        return curr->isEnd;
    }
    return true;
}