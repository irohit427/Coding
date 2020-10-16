#include<bits/stdc++.h>
using namespace std;

double distance(pair<int, int> p) {
    return sqrt(p.first*p.first + p.second*p.second);
}

vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
    priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq;

    for (int i = 0; i < points.size(); i++) {
        pq.push({distance({points[i][0], points[i][1]}), i});
    }
    vector<vector<int>> res;
    while(K--) {
        res.push_back(points[pq.top().second]);
        pq.pop();
    }
    return res;
}