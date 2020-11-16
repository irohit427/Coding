#include<bits/stdc++.h>
using namespace std;

int minMeetingRooms(vector<vector<int>>& intervals) {

    if (intervals.size() < 2)
        return intervals.size();

    priority_queue<int, vector<int>, greater<int>> pq;
    sort(intervals.begin(), intervals.end());

    pq.push(intervals[0][1]);

    for (int i = 1; i < intervals.size(); i++) {
        if (intervals[i][0] >= pq.top()) {
            pq.top();
        }
        pq.push(intervals[i][1]);
    }

    return pq.size();
}