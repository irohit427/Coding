#include<bits/stdc++.h>
using namespace std;

bool canJump(vector<int>& nums) {
    int jump = 0;
    for (int i = 0; i < nums.size() -1; i++) {
        jump = nums[i] > jump ? nums[i] : jump;
        if (jump == 0)
            return false;
        jump--;
    }
    return true;
}