#include<bits/stdc++.h>
using namespace std;

struct bin {
    int temperature, index;
};

typedef stack<bin> Stack;
vector<int> dailyTemperatures(vector<int>& T) {
    int n = T.size();
    vector<int> result(n);
    Stack stk;
    int index;
    for (int i = 0; i < n; i++) {
        while(!stk.empty() && T[i] > stk.top().temperature) {
            index = stk.top().index;
            result[index] = i - index;
            stk.pop();
        }
        stk.push(bin{T[i], i});
    }
    return result;
}