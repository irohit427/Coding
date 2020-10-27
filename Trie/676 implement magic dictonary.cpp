#include<bits/stdc++.h>
using namespace std;

struct TrieNode {
    bool isEnd;
    vector<TrieNode*> children;
    TrieNode(): isEnd(false), children(vector<TrieNode*>(26, nullptr)) {}
};

TrieNode* root;
MagicDictionary() {
    root = new TrieNode();
}

/** Build a dictionary through a list of words */
void buildDict(vector<string> dict) {
    for(string word: dict) {
        insert(word);
    }
}

/** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
bool search(string word) {
    TrieNode* curr = root;
    int diff = 0;
    for (int i = 0; i < word.length(); i++) {
        for (int j = 0; j < 26; j++) {
            if (curr->children[j] == curr->children[word[i] - 'a']) continue;
            if (curr->children[j] && find(curr->children[j], word.substr(i + 1))) return true;
        }
        if (curr->children[word[i] - 'a'])
            curr = curr->children[word[i] - 'a'];
    }
    return false;
}

void insert(string word) {
    TrieNode* curr = root;
    for (int i = 0; i < word.length(); i++) {
        if (curr->children[word[i] - 'a'] == nullptr)
            curr->children[word[i] - 'a'] = new TrieNode();
        curr = curr->children[word[i] - 'a'];
    }
    curr->isEnd = true;
}

bool find(TrieNode* curr, string word) {
    for (int i = 0; i < word.length(); i++) {
        if (curr->children[word[i] - 'a'] == nullptr)
            return false;
        curr = curr->children[word[i] - 'a'];
    }
    return curr->isEnd;
}