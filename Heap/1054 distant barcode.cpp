#include<bits/stdc++.h>
using namespace std;

vector<int> rearrangeBarcodes(vector<int>& barcodes) {
    unordered_map<int, int> hmap;
    for (int i: barcodes) {
        hmap[i]++;
    }

    priority_queue<pair<int, int>> pq;
    for (auto m: hmap) {
        pq.push({m.second, m.first});
    }

    vector<int> res(barcodes.size());
    int index = 0;
    while(!pq.empty()) {
        for (int i = 0; i < pq.top().first; i++) {
            if (index >= res.size()) {
                index = 1;
            }
            res[index] = pq.top().second; 
            index += 2;
        }
        pq.pop();
    }
    return res;
}