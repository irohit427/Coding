#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
  unordered_map<int, int> comp;
  for (int i = 0; i < nums.size(); i++) {
    if (comp.find(nums[i]) != comp.end()) {
      return {comp[nums[i]], i};
    }
    comp[target - nums[i]] = i;
  }
  return {};       
}