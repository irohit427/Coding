#include<bits/stdc++.h>
using namespace std;

struct TrieNode {
    string word;
    vector<TrieNode*> children;
    TrieNode(): word(""), children(vector<TrieNode*>(26, nullptr)) {}
};

TrieNode* root = new TrieNode();
vector<pair<int, int>> dirs{{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
vector<string> result;

vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    for (string word: words) {
        insert(word);
    }
    int rows = board.size(), cols = board[0].size();
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (root->children[board[i][j] - 'a'] != nullptr)
                search(board, i, j, root);
        }
    }
    return result;
}

void search(vector<vector<char>>& board, int i, int j, TrieNode* curr) {
    int rows = board.size(), cols = board[0].size();
    int idx = board[i][j] - 'a';
    if (curr->children[idx] != nullptr) {
        curr = curr->children[idx];
        if (curr->word != "") {
            result.emplace_back(curr->word);
            curr->word = "";
        }

        char letter = board[i][j];
        board[i][j] = '*';
        for (int k = 0; k < 4; k++) {
            pair<int, int> dir = dirs[k];
            int x = i + dir.first, y = j + dir.second;
                
            if (x < rows && x >= 0 && y < cols && y >= 0 && board[x][y] != '*') {
                search(board, x, y, curr);
            }
        }
        board[i][j] = letter;
    }
}

void insert(string word) {
    TrieNode* curr = root;
    for (int i = 0; i < word.size(); i++) {
        if (curr->children[word[i] - 'a'] == nullptr)
            curr->children[word[i] - 'a'] = new TrieNode();
        curr = curr->children[word[i] - 'a'];
    }
    curr->word = word;
}