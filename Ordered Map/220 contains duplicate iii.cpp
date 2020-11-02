#include<bits/stdc++.h>
using namespace std;

bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    vector<pair<int, int>> duplicate;
    for (int i = 0; i < nums.size(); i++) {
        duplicate.push_back({nums[i], i});
    }
    sort(duplicate.begin(), duplicate.end());

    for (int i = 0; i < nums.size(); i++) {
        for (int j = i + 1; j < nums.size(); j++) {
            if (duplicate[i].first + t >= duplicate[j].first && abs(duplicate[i].second - duplicate[j].second) <= k) {
                return true;
            } else {
                break;
            }
        }
    }
    return false;
}