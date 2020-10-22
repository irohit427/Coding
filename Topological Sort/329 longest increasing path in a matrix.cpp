#include<bits/stdc++.h>
using namespace std;


vector<pair<int, int>> dirs {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int longestIncreasingPath(vector<vector<int>>& matrix) {
    if (matrix.size() == 0) {
        return 0;
    }
    int rows = matrix.size(), cols = matrix[0].size();
    vector<vector<int>> indegree(rows, vector<int>(cols, 0));

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {

            for (auto dir: dirs) {
                int nx = i + dir.first;
                int ny = j + dir.second;

                if (nx >= 0 && nx < rows && ny >= 0 && ny < cols) {
                    if (matrix[nx][ny] > matrix[i][j])
                        indegree[i][j]++;
                }
            }
        }
    }

    queue<pair<int, int>> q;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (indegree[i][j] == 0)
                q.push({i, j});
        }
    }

    int ans = 0;
    while (! q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            pair<int, int> top = q.front();
            q.pop();
            for (auto dir: dirs) {
                int nx = top.first + dir.first;
                int ny = top.second + dir.second;
                if (nx >= 0 && nx < rows && ny >= 0 && ny < cols) {
                    if (matrix[nx][ny] < matrix[top.first][top.second]) {
                        --indegree[nx][ny];
                        if (indegree[nx][ny] == 0) {
                            q.push({nx, ny});
                        }
                    }
                    
                }
            }
        }
        ans++;
    }
    return ans;
}