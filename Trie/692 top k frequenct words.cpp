#include<bits/stdc++.h>
using namespace std;

vector<string> topKFrequent(vector<string>& words, int k) {
    map<string, int> hmap;
    for (int i = 0; i < words.size(); i++) {
        hmap[words[i]]++;
    }

    priority_queue<pair<string, int>, vector<pair<string, int>>, comparision> pq;
    for (auto m: hmap) {
        pq.push(m);
        if (pq.size() > k) pq.pop();
    }
    vector<string> result;
    while(!pq.empty()) {
        result.insert(result.begin(), pq.top().first);
        pq.pop();
    }
    return result;
}

struct comparision {
    bool operator() (pair<string, int> a, pair<string, int> b) {
        if (a.second != b.second) {
            return a.second > b.second;
        }
        return a.first < b.first;
    }
};