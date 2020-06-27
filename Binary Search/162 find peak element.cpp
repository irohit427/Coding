#include<bits/stdc++.h>
using namespace std;

int findPeakElement(vector<int>& nums) {
    int l = 0, r = nums.size()-2, mid;
    while(l <= r) {
        mid = l + (r - l) / 2;
        if (nums[mid + 1] > nums[mid]) l = mid + 1;
        else r = mid - 1;
    }
    return l;
}