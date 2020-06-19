#include<bits/stdc++.h>
using namespace std;

typedef stack<pair<int, int>> Stack;

Stack stk;

void push(int n) {
    if (stk.empty()) stk.push({n, n});
    else stk.push({n, min(n, stk.top().second)});
}

void pop() {
    stk.pop();
}

int top() {
    return stk.top().first;
}

int min() {
    return stk.top().second;
}