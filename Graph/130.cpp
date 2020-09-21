#include<bits/stdc++.h>
using namespace std;

vector<pair<int, int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
bool isBorder(pair<int, int> cell, int row, int col) {
    if (cell.first == 0 || cell.second == 0 || cell.first == row-1 || cell.second == col-1)
        return true;
    return false;
}

bool isSafe(pair<int, int> cell, int row, int col) {
    if (cell.first >= 0 && cell.first < row && cell.second >= 0 && cell.second < col)
        return true;
    return false;
}


void solve(vector<vector<char>>& board) {
    int row = board.size(), col = board[0].size();
    queue<pair<int, int>> q;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (board[i][j] == 'O' && isBorder({i,j}, row, col)) {
                board[i][j] = '.';
                q.push({i, j});
            }
        }
    }

    while (!q.empty()) {
        auto curr = q.front();
        q.pop();

        for (int i = 0; i < dir.size(); i++) {
            int dx = curr.first + dir[i].first, dy = curr.second + dir[i].second;
            if (isSafe({dx, dy}, row, col)
                && board[dx][dy] == 'O' 
                && !isBorder({dx, dy}, row, col)) {
                    board[dx][dy] = '.';
                    q.push({dx, dy});
            }
        }
    }

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (board[i][j] == '.')
                board[i][j] = 'O';
            else if (board[i][j] == 'O')
                board[i][j] = 'X';
        }
    }
}