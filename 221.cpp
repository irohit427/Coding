#include<bits/stdc++.h>
using namespace std;

struct bin {
  int height, index;
};
  
int maximalSquare(vector<vector<char>>& matrix) {
  int row = matrix.size(), column = matrix[0].size();
  vector<int> heights(column, 0);
  int area = 0;
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < column; j++) {
      heights[j] = matrix[i][j] == '1' ? heights[j] + 1 : 0;
    }
    area = max(area, maxArea(heights));
  }
  return area;
}

int maxArea (vector<int>& height) {
  stack<bin> st;
  int maxsquare = 0, edge, i;
  for (i = 0; i < height.size();) {
      if (st.empty() || height[i] >= st.top().height)
          st.push(bin{height[i], i++});
      else {
          int top = st.top().height;
          st.pop();
          edge = st.empty() ? min(top, i) : min(top, i-st.top().index-1);
          maxsquare = max(edge * edge, maxsquare);
      }
  }
  while (!st.empty()) {
      int top = st.top().height;
      st.pop();
    edge = st.empty() ? min(top, i) : min(top, i-st.top().index-1);
    maxsquare = max(edge * edge, maxsquare);
  }
  return maxsquare;
}