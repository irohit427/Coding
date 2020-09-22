#include<bits/stdc++.h>
using namespace std;
vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
bool isSafe(pair<int, int> cell, int row, int col) {
    if (cell.first >= 0 && cell.second >= 0 && cell.first < row && cell.second < col)
        return true;
    return false;
}
int maxDistance(vector<vector<int>>& grid) {
    int row = grid.size(), col = grid[0].size();
    queue<pair<int, int>> q;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (grid[i][j] == 1) {
                q.push({i, j});
            }
        }
    }
    int maxDistance = 0;
    if (q.size() == 0 || q.size() == row*col) 
        return -1;
    int level = 0;
    while(!q.empty()) {
        auto curr = q.front();
        q.pop();
        for (int i = 0; i < dir.size(); i++) {
            int dx = curr.first + dir[i].first;
            int dy = curr.second + dir[i].second;
            if (isSafe({dx, dy}, row, col) && grid[dx][dy] == 0) {
                q.push({dx, dy});
                grid[dx][dy] = 1 + grid[curr.first][curr.second];
                maxDistance = max(maxDistance, grid[dx][dy]);
            }
        }
    }
    return maxDistance -1;
}