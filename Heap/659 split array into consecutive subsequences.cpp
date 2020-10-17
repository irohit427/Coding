#include<bits/stdc++.h>
using namespace std;

bool isPossible(vector<int>& nums) {
    unordered_map<int, priority_queue<int, vector<int>, greater<int>>> hmap;

    for (int i = 0; i < nums.size(); i++) {
        if (hmap[nums[i] - 1].size() > 0) {
            int l = hmap[nums[i] - 1].top() + 1;
            hmap[nums[i]].push(l);
            hmap[nums[i] - 1].pop();
        } else {
            hmap[nums[i]].push(1);
        }
    }

    for (auto m: hmap) {
        if (m.second.size() > 0 && m.second.top() < 3)
        return false;
    }   
    return true;
}