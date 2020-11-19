#include<bits/stdc++.h>
using namespace std;
vector<int> parent;
int find(int x) {
    return x == parent[x] ? x: find(parent[x]);
}

vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
    if (accounts.size() == 1) {
        sort(accounts[0].begin() + 1, accounts[0].end());
        return accounts;
    }        
    unordered_map<string, int> hmap;
    vector<string> nameMap(accounts.size(), ""); 
    parent.resize(accounts.size(), -1);
    for (int i = 0; i < accounts.size(); i++) {
        parent[i] = i;
        nameMap[i] = accounts[i][0];
        for (int j = 1; j < accounts[i].size(); j++) {
            if (hmap.find(accounts[i][j]) == hmap.end()) {
                hmap[accounts[i][j]] = i;
            } else {
                parent[find(i)] = find(hmap[accounts[i][j]]);
            }
        }
    }
    unordered_map<int, vector<string>> resMap;
    for (auto m: hmap) {
        int p = find(m.second);
        resMap[p].push_back(m.first);
    }
    vector<vector<string>> res;
    for (auto m: resMap) {
        sort(m.second.begin(), m.second.end());
        m.second.insert(m.second.begin(), nameMap[m.first]);
        res.push_back(m.second);
    }
    return res;
}