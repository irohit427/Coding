#include<bits/stdc++.h>
using namespace std;

struct TrieNode {
    bool isEnd;
    vector<TrieNode*> children;
    TrieNode(): isEnd(false), children(vector<TrieNode*>(26, nullptr)) {}
};

TrieNode* root = new TrieNode();

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

vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
    for (string word: words) {
        insert(word);
    }
    vector<string> result;
    for (string word: words) {
        if (isConcatenated(word)) 
            result.push_back(word);
    }
    return result;
}

bool isConcatenated(string word) {
    TrieNode* curr = root;
    for (int i = 0; i < word.length(); i++) {
        if (curr->children[word[i] - 'a'] == nullptr)
            return false;
        string suffix = word.substr(i + 1);
        if (curr->isEnd && search(suffix) || isConcatenated(suffix))
            return true;
    }
    return false;
}

bool search(string word) {
    TrieNode* curr = root;
    for (int i = 0; i < word.length(); i++) {
        curr = curr->children[word[i] - 'a'];
        if (curr == nullptr)
            return false;
    }
    return curr->isEnd;
}
