#include<bits/stdc++.h>
using namespace std;

string longestWord(vector<string>& words) {
    sort(words.begin(), words.end());
    unordered_set<string> candidates = {""};
    string res;
    for (string word: words) {
        if (candidates.count(word.substr(0, word.length() - 1))) {
            candidates.insert(word);
            if (word.size() > res.size())
                res = word; 
        }
    }        
    return res;
}