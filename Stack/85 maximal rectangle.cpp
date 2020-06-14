#include<bits/stdc++.h>
using namespace std;

struct bin {
    int height; 
    int index;
};

typedef stack<bin> Stack;

int maximalRectangle(vector<vector<int>>& matrix) {
    int l = matrix[0].size();
    vector<int> heights(l, 0);
    int area = -1;
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[0].size(); j++) {
            heights[j] = matrix[i][j] == '1' ? heights[j] + 1: 0;
        }
        area = max(area, maxRectangle(heights));
    }
    return area;
}

int maxRectangle(vector<int>& heights) {
    Stack stk;
    int height, width, area = 0;
    int i = 0;
    while(i < heights.size()) {
        if (stk.empty() || heights[i] > stk.top().height) {
            stk.push(bin{heights[i], i});
            i++;
        } else {
            height = stk.top().height;
            stk.pop();
            width = stk.empty() ? i : i - stk.top().index - 1;
            area = max(area, height * width);
        }
    }

    while(!stk.empty()) {
        height = stk.top().height;
            stk.pop();
            width = stk.empty() ? i : i - stk.top().index - 1;
            area = max(area, height * width);
    }
    return area;
}

