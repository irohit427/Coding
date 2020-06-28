#include<bits/stdc++.h>
using namespace std;

int search(vector<int>& nums, int target) {
    int l = 0, r = nums.size() - 1, mid, ans = -1;
    while (l <= r) {
        mid = l + (r - l) / 2;
        if (nums[mid] == target) ans = mid;
        // check where does the mid lie
        if (nums[l] <= nums[mid]) {
            if (nums[l] <= target && target < nums[mid]) r = mid - 1;
            else l = mid + 1;
        } else {
            if (nums[mid] < target && target <= nums[r]) l = mid + 1;
            else r = mid - 1;
        }
    }    
    return ans;    
}