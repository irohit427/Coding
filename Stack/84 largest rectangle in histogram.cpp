#include<bits/stdc++.h>
using namespace std;

struct bin {
    int height;
    int index;
};

typedef stack<bin>  Stack;

int largestRectangleArea(vector<int>& arr) {
    Stack stk;
    int i = 0, area = 0, top, height, width;
    while(i < arr.size()) {

        if (stk.empty() || stk.top().height <= arr[i]) {
            stk.push(bin{arr[i], i});
            i++;
        } else {
            height = stk.top().height;
            stk.pop();
            width = stk.empty() ? i: i - stk.top().index - 1;
            area = max(area, height * width);
        }
    }

    while (!stk.empty()) {
        height = stk.top().height;
        stk.pop();
        width = stk.empty() ? i : i - stk.top().index - 1;
        area = max(area, height * width);
    }
    return area;
}