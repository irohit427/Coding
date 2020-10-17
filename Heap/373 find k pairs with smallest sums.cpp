#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int,int>>>> pq;
    for(int n1: nums1) {
        for (int n2: nums2) {
            pq.push({n1 + n2, {n1, n2}});
        }
    }
    vector<vector<int>> res;
    while(!pq.empty()) {
        auto p = pq.top();
        vector<int> temp(2);
        temp[0] = p.second.first;
        temp[1] = p.second.second;
        res.push_back(temp);
        if (res.size() == k)
            break;
        pq.pop();
    }
    return res;
}