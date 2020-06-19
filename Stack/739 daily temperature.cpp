#include<bits/stdc++.h>
using namespace std;
struct bin {
    int temperature, index;
};

typedef stack<bin> Stack;

vector<int> dailyTemperatures(vector<int>& T) {
    Stack stk;
    int n = T.size();
    vector<int> res(n, 0);
    for (int i = T.size()-1; i >= 0; i--) {
        if (stk.empty() || stk.top().temperature > T[i]) {
            stk.push(bin{T[i], i});
            res[i] = 1;
        } else {
            while(T[i] > stk.top().temperature) {
                stk.pop();
            }
            res[i] = stk.top().index - i;
        }
    }
    return res;        
}