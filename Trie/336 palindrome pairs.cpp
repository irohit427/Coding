#include<bits/stdc++.h>
using namespace std;

struct TrieNode {
    bool isEnd;
    vector<TrieNode*> children;
    TrieNode(): isEnd(false), children(vector<TrieNode*>(26, nullptr)) {}
};

bool isPalindrome(string s) {
    int i = 0, j = s.length() - 1;
    while(i < j) {
        if (s[i++] != s[j--])   return false;
    }
    return true;
}

TrieNode* root = new TrieNode();

vector<vector<int>> palindromePairs(vector<string>& words) {
    map<string, int> hmap;
    for (int i = 0; i < words.size(); i++) {
        string word = words[i];
        reverse(word.begin(), word.end());
        hmap[word] = i;
        insert(word);
    }
    vector<vector<int>> ans;
    if (hmap.count("")) {
        for (int i = 0; i < words.size(); i++) {
            if (words[i] != "" && isPalindrome(words[i])) {
                ans.push_back({hmap[""], i});
            }
        }
    }

    for (int i = 0; i < words.size(); i++) {
        string word = words[i];
        for (int j = 0; j < word.length(); j++) {
            string left = word.substr(0, j), right = word.substr(j);
            if (find(left) && isPalindrome(right) && hmap[left] != i) 
                ans.push_back({i, hmap[left]});

            if (find(right) && isPalindrome(left) && hmap[right] != i)
                ans.push_back({hmap[right], i});
        }
    }
    return ans;
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

bool find(string word) {
    TrieNode* curr = root;
    for (int i = 0; i < word.length(); i++) {
        if (curr->children[word[i] - 'a'] == nullptr)
            return false;
        curr = curr->children[word[i] - 'a'];
    }
    return curr->isEnd ? true: false;
}


vector<vector<int>> palindromePairs(vector<string>& words) {
    unordered_map<string, int> hmap;
    for (int i = 0; i < words.size(); i++) {
        string word = words[i];
        reverse(word.begin(), word.end());
        hmap[word] = i;
    }

    vector<vector<int>> result;
    if (hmap.count("")) {
        for(int i = 0; i < words.size(); i++) {
            if (words[i] != "" && isPalindrome(words[i])) {
                result.push_back({hmap[""], i});
            }
        }
    }

    for (int i = 0; i < words.size(); i++) {
        string word = words[i];
        for (int j = 0; j < word.length(); j++) {
            string left = word.substr(0, j), right = word.substr(j);
            if (hmap.count(left) && isPalindrome(right) && hmap[left] != i)
                result.push_back({i, hmap[left]});
            
            if (hmap.count(right) && isPalindrome(left) && hmap[right] != i)
                result.push_back({hmap[right], i});
        }
    }
    return result;
}