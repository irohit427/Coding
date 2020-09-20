#include<bits/stdc++.h>
using namespace std;
vector<int> parent;

int find(int x) {
    return x == parent[x] ? x: find(parent[x]);
}

int findCircleNum(vector<vector<int>>& M) {
    int n = M.size();
    int count = n;
    parent.resize(n);
    for (int i = 0; i < n; ++i) {
        parent[i] = i;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            if (M[i][j] == 1) {
                int x = find(i);
                int y = find(j);
                if (x != y) {
                    parent[y] = x;
                    count--;      
                }
            }
        }
    }
    return count;
}