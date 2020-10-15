#include<bits/stdc++.h>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    priority_queue<pair<int, int>> pq;
    int n = nums.size();
    vector<int> result(n - k + 1);
    int start = 0;
    for (int i = 0; i < nums.size(); i++) {
        pq.push({nums[i], i});

        if (i - start + 1 == k) {
            while (pq.top().second < start) {
                pq.pop();
            }
            result[i - k + 1] = pq.top().first;
            start++;
        }
    }    
    return result;    
}

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> dq;

    vector<int> ans;
    for (int i = 0; i < nums.size(); i++) {
        if (!dq.empty() && dq.front() == i - k) dq.pop_front();

        while(!dq.empty() && nums[dq.back()] < nums[i]) dq.pop_back();
        dq.push_back(i);
        if (i - k + 1 >= 0) ans.push_back(nums[dq.front()]);
    }
    return ans;
}