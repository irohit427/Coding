#include<bits/stdc++.h>
using namespace std;

void add(vector<int> &fenwick, int n, int x) {
    for (; x < n; x |= x+1)
      fenwick[x]++;
}
int getSum(vector<int> &fenwick, int x) {
    int s = 0;
    for (; x; x &= x-1)
        s += fenwick[x-1];
    return s;
}
int countRangeSum(vector<int>& nums, int lower, int upper) {
    int n = nums.size();
    long s = 0, cnt = 0;
    vector<int> fenwick(n+1, 0);
    vector<long> scale;
    scale.push_back(0);
    for (int x: nums)
        scale.push_back(s += x);
    sort(scale.begin(), scale.end());
    s = 0;
    add(fenwick, n+1, lower_bound(scale.begin(), scale.end(), 0) - scale.begin());
    for (int x: nums) {
        s += x;
        cnt += getSum(fenwick, upper_bound(scale.begin(), scale.end(), s-lower) - scale.begin()) -
        getSum(fenwick, lower_bound(scale.begin(), scale.end(), s-upper) - scale.begin());
        add(fenwick, n+1, lower_bound(scale.begin(), scale.end(), s) - scale.begin());
    }
    return cnt;
}