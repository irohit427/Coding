#include<bits/stdc++.h>
using namespace std;

vector<pair<int, int>> dir {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
bool isBorder(pair<int, int> cell, int row, int col) {
    if (cell.first == 0 | cell.second == 0 || cell.first == row - 1 || cell.second == col - 1)
        return true;
    return false;
}

bool isSafe(pair<int, int> cell, int row, int col) {
    if (cell.first >= 0 && cell.second >= 0 && cell.first < row && cell.second < col)
        return true;
    return false;
}

int numEnclaves(vector<vector<int>>& A) {
    if(A.size() == 0) return 0;
    int row = A.size(), col = A[0].size();
    vector<vector<int>> visited(row, vector<int>(col, 0));
    queue<pair<int, int>> q;
    int ans = 0;
    vector<pair<int, int>> points;
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            if (A[i][j] == 0) {
                visited[i][j] = 1;
            } else {
                visited[i][j] = 0;
                ans++;
                if (isBorder({i, j}, row, col))
                    points.push_back({i,j});
            }
        }
    }

    for (int i = 0; i < points.size(); i++) {
        int count = 0;
        q.push(points[i]);
        while(!q.empty()) {
            auto curr = q.front();
            q.pop();
            count++;
            visited[curr.first][curr.second] = 1;
            for(int i = 0; i < dir.size(); i++) {
                int dx = curr.first + dir[i].first, dy = curr.second + dir[i].second;
                if (isSafe({dx, dy}, row, col) && visited[dx][dy] == 0) {
                    q.push({dx, dy});
                }
            }
        }
        ans -= count;
    }
    return ans;
}