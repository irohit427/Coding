#include<bits/stdc++.h>
using namespace std;

vector<int> island;
set<vector<int>> islands;
int row, col, start;
int numDistinctIslands(vector<vector<int>>& grid) {
  
  row = grid.size(), col = grid[0].size();
  
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      
      start = i * col + j;
      
      if (grid[i][j] == 1) {
        dfs(grid, i, j);
        islands.insert(island);
        island.clear();
      }
    }
  }
  return islands.size();
}

void dfs(vector<vector<int>>& grid, int i, int j) {

if (i < 0 || i >= row || j < 0 || j >= col || grid[i][j] != 1) {
    return;
  }

  grid[i][j] = 2;

island.emplace_back(i * col + j - start);
  dfs(grid, i - 1, j);
  dfs(grid, i + 1, j);
  dfs(grid, i, j - 1);
  dfs(grid, i, j + 1);
}
