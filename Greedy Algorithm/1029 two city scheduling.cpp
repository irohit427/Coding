#include<bits/stdc++.h>
using namespace std;

int twoCitySchedCost(vector<vector<int>>& costs) {
    int n = costs.size();
    priority_queue<pair<int, int>> pq;

    for (int i = 0; i < n; i++) {
        pq.push({costs[i][0] - costs[i][1], i});
    }        
    int ans = 0;
    for (int i = 0; i < n/2; i++) {
        ans += costs[pq.top().second][1];
        pq.pop();
    }

    for (int i = 0; i < n/2; i++) {
        ans += costs[pq.top().second][0];
        pq.pop();
    }
    return ans;
}