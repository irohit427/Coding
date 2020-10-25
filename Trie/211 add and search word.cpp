#include<bits/stdc++.h>
using namespace std;

struct TrieNode {
    bool isEnd;
    vector<TrieNode*> children;
    TrieNode(): isEnd(false), children(vector<TrieNode*>(26, nullptr)) {} 
};

TrieNode* root = new TrieNode();
WordDictionary() {
}

void addWord(string word) {
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
   return searchHelper(word, root);
}

bool searchHelper(char* word, TrieNode* curr) {
    for (int i = 0; word[i] && curr; i++) {
            if (word[i] != '.') {
                curr = curr -> children[word[i] - 'a'];
            } else {
                TrieNode* tmp = curr;
                for (int j = 0; j < 26; j++) {
                    curr = tmp -> children[j];
                    if (searchHelper(word + i + 1, curr)) {
                        return true;
                    }
                }
            }
        }
        return curr && curr -> word;
}

unordered_map<int, vector<string> > Dictionary;

WordDictionary() {
        
}

void addWord(string word) {
    Dictionary[word.length()].push_back(word);
}

bool search(string word) {
    for (auto s : Dictionary[word.length()]) {
        int i, len = word.length();
        for (i = 0; i < len; i++) {
            if (word[i] != s[i] && word[i] != '.')
                break;
        }
        if (i == len)
            return true;
    }
    return false;
}

WordDictionary() {
        
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        dict[word.length()].push_back(word);
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        if (dict[word.length()].empty() != true){
            for (string& wd : dict[word.length()]){
                if (isEqual(wd, word)) return true;
            }
        }
        return false;
    }
    
unordered_map<int, vector<string>> dict;
    bool isEqual(string&wd, string& word){
        for (int i = 0; i < word.length(); i++){
            if (word[i] == '.') continue;
            if (word[i] != wd[i]) return false;
        }
        return true;
    }