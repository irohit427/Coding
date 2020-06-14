#include<bits/stdc++.h>
using namespace std;

struct bin {
    int height;
    int index;
};
typedef stack<bin> Stack;

int trap(vector<int>& heights) {
    int water = 0, i = 0, height, width, bounded_height;
        Stack stk;
        while( i < heights.size()) {
            if (stk.empty() || heights[i] <= stk.top().height) {
                stk.push(bin{heights[i], i});
                i++;
            } else {
                height = stk.top().height;
                stk.pop();
                if (stk.empty()) continue;
                width = i - stk.top().index - 1;
                bounded_height = min(stk.top().height, heights[i]) - height;
                water += (width * bounded_height);
            }
        }
    return water;
}