#include<bits/stdc++.h>
using namespace std;
vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}, {1, -1}, {-1, 1}, {1, 1}, {-1, -1}};

bool isSafe(pair<int, int> cell, int row, int col) {
    if (cell.first >= 0 && cell.second >= 0 && cell.first < row && cell.second < col)
        return true;
    return false;
}

int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    int row = grid.size(), col = grid[0].size();
    if (grid[0][0] == 1 || grid[row-1][col-1] == 1)
        return -1;
    vector<vector<int>> visited(row, vector<int>(col, 0));
    queue<pair<int, int>> q;
    q.push({0,0});
    grid[0][0] = 1;
    while(!q.empty()) {
        auto curr = q.front();
        q.pop();
        visited[curr.first][curr.second] = 1;
        for (int i = 0; i < dir.size(); i++) {
            int dx = curr.first + dir[i].first;
            int dy = curr.second + dir[i].second;
            if (isSafe({dx, dy}, row, col) && !visited[dx][dy] && grid[dx][dy] == 0) {
                q.push({dx, dy});
                grid[dx][dy] = 1 + grid[curr.first][curr.second];
            }           
        }
    }
    return grid[row-1][col-1] == 0 ? -1: grid[row-1][col-1];
}