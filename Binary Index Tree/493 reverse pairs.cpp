#include<bits/stdc++.h>
using namespace std;

int reversePairs(vector<int>& nums) {
    if (nums.size() == 0) return 0;

    vector<long> clone;
    for (long n: nums) {
        clone.push_back(2 * n);
    }        

    set<long> sorted;
    sorted.insert(nums.begin(), nums.end());
    sorted.insert(clone.begin(), clone.end());

    unordered_map<long, int> ranks;

    int rank = 0;
    for (long n: sorted) {
        ranks[n] = ++rank;
    }
    vector<int> bit(rank + 1, 0);

    int res;
    for (int i = clone.size() - 1; i >= 0; i--) {
        res += query(bit, ranks[clone[i] / 2] - 1);
        update(bit, ranks[clone[i]], 1);
    }
    return res;
}

int lsb(int index) {
    return index & -index;
}

int query(vector<int>& bit, int index) {
    int sum = 0;
    while(index) {
        sum += bit[index];
        index -= lsb(index);
    }
    return sum;
}

void update(vector<int>& bit, int index, int delta) {
    while(index < bit.size()) {
        bit[index] += delta;
        index += lsb(index);
    }
}