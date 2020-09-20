#include<bits/stdc++.h>
using namespace std;

int networkDelayTime(vector<vector<int>>& times, int N, int K) {
    vector<vector<pair<int,int>>> graph(N+1);    
    for (auto t: times) {
        graph[t[0]].push_back({t[1], t[2]});
    }
    queue<pair<int,int>> q;
    vector<int> cost(N + 1, INT_MAX);
    q.push({K, 0});
    cost[K] = 0;
    while(!q.empty()) {
        auto curr = q.front();
        q.pop();
        for (auto e: graph[curr.first]) {
            if (curr.second + e.second < cost[e.first]) {
                cost[e.first] = curr.second + e.second;
                q.push({e.first, cost[e.first]});
            }
        }
    }
    int max_cost = *max_element(cost.begin() + 1, cost.end());
    return max_cost != INT_MAX ? max_cost: -1;