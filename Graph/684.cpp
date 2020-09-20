#include <bits/stdc++.h>
using namespace std;
vector<int> parent;
int find(int n) {
    return n == parent[n] ? n: find(parent[n]);
}
vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    int n = edges.size();
    parent.resize(n+1, 0);

    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }
    vector<int> result(2);
    for (int i = 0; i < n; i++) {
        int x = find(edges[i][0]);
        int y = find(edges[i][1]);
        if (x != y) {
            parent[y] = x;
        } else {
            result[0] = edges[i][0];
            result[1] = edges[i][1];
        }       
    }
    return result;
}