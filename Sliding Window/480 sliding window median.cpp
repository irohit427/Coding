#include<bits/stdc++.h>
using namespace std;

vector<double> medianSlidingWindow(vector<int>& nums, int k) {
    int n = nums.size();

    vector<double> result(n - k + 1);
    multiset<double> window(nums.begin(), nums.begin() + k);
    auto m = next(window.begin(), k/2);
    for (int i = k; i < n;i++) {
        result[i - k] = (*m + *next(m, k % 2 - 1)) / 2;
        window.insert(nums[i]);
        if (nums[i] < *m)
            m--;
        if (nums[i-k] <= *m)
            m++;
        window.erase(window.lower_bound(nums[i-k]));
    }     
    return result;
}