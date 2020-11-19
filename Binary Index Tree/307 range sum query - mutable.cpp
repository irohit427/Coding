#include<bits/stdc++.h>
using namespace std;

int lsb(int index) {
    return index & -index;
}

vector<int> bit;
vector<int> num;
NumArray(vector<int>& nums) {
    int n = nums.size();
    bit.resize(n+1);
    num.resize(n);
    for (int i = 0; i <= n; i++) {
        bit[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        update(i, nums[i]);
    }

    for (int i = 0; i < n; i++) {
        num[i] = nums[i];
    }
}

void update(int i, int val) {
    i = i + 1;

    for (int index = i; index < bit.size(); index += lsb(index)) {
        bit[index] += val - num[i-1]; 
    }

    num[i-1] = val;
}

int sumRange(int i, int j) {
    return getSum(j) - getSum(i-1);
}
int getSum(int index) {
    index = index + 1;
    int s = 0;
    for (int i = index; i > 0; i -= lsb(i)) {
        s += bit[i];
    }
    return s;
}