#include<bits/stdc++.h>
using namespace std;

vector<int> stk;
int index = 0;
CustomStack(int maxSize) {
    stk = vector<int>(maxSize);
}

void push(int x) {
    if (index < stk.size()) {
        stk[index] = x;
        index++;
    }
}

int pop() {
    return index >= 0 ? stk[index--] : -1;
}

void increment(int k, int val) {
    k = min (k, index);
    for (int i = 0; i < k; i++) {
        stk[i] += val;
    }
}