#include <bits/stdc++.h>
using namespace std;
vector<int> parent;
int find(int x) {
    return x == parent[x] ? x: find(parent[x]);
}
int makeConnected(int n, vector<vector<int>>& connections) {
    parent.resize(n);
    int total = connections.size(), must = 0;
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }
    for (int i = 0; i < connections.size(); i++) {
        int x = find(connections[i][0]);
        int y = find(connections[i][1]);
        if (x != y) {
            must++;
            parent[y] = x;
        }
    }

    int component = 0;
    for (int i = 0; i < n; i++) {
        component = component + (parent[i] == i);
    }
    return total - must >= component - 1 ? component - 1: -1;
}