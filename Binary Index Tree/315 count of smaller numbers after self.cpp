#include<bits/stdc++.h>
using namespace std;

vector<int> countSmaller(vector<int>& nums) {

    if (nums.size() == 0)   return {};

    int minimum = INT_MAX, maximum = INT_MIN;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        minimum = min(minimum, nums[i]);
    }       

    vector<int> num(n);

    for (int i = 0; i < n; i++) {
        num[i] = nums[i] - minimum + 1;
        maximum = max(maximum, num[i]);
    }

    vector<int> tree(maximum + 1);
    vector<int> result;
    for (int i = num.size() - 1; i >= 0; i--) {
        result.push_back(get(num[i] - 1, tree));
        update(num[i], tree);
    }
    reverse(result.begin(), result.end());
    return result;
}

int lsb(int index) {
    return index & -index;
}

int get(int index, vector<int>& tree) {
    int num = 0;
    while(index) {
        num += tree[index];
        index -= lsb(index);
    }
    return num;
}

void update(int index, vector<int>& tree) {
    while(index < tree.size()) {
        tree[index] = tree[index] + 1;
        index += lsb(index);
    }
}