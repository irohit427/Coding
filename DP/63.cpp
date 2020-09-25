#include<bits/stdc++.h>
using namespace std;

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
  int r = obstacleGrid.size(), c = obstacleGrid[0].size();
  vector<vector<int>> dp(r, vector<int>(c, 0));

  for (int i = 0; i < r; i++) {
    if (obstacleGrid[i][0] != 1)
      dp[i][0] = 1;
    else break;
  }

  for (int i = 0; i < c; i++) {
    if (obstacleGrid[0][i] != 1)
      dp[0][i] = 1;
    else break;
  }

  for (int i = 1; i < r; i++) {
    for (int j = 1; j < c; j++) {
      if (obstacleGrid[i][j] != 1) {
        dp[i][j] = dp[i-1][j] + dp[i][j-1];
      }
    }
  }
  return dp[r-1][c-1];
}