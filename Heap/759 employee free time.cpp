#include<bits/stdc++.h>
using namespace std;

class Interval {
public:
    int start;
    int end;

    Interval() {}

    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};

struct compare {
    bool operator() (Interval a, Interval b) {
        return a.start > b.start;
    }
};

vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
    vector<Interval> temp;
    vector<Interval> result;
    priority_queue<Interval, vector<Interval>, compare> pq;
    for (int i = 0; i < schedule.size(); i++) {
        for (int j = 0; j < schedule[i].size(); j++) {
            pq.push(schedule[i][j]);
        }
    }
    Interval val = pq.top();
    pq.pop();
    while(pq.size()) {
        Interval top = pq.top();
        pq.pop();

        if (val.end < top.start) {
            temp.push_back(val);
            val = top;
        } else {
            val.start = min(val.start, top.start);
            val.end = max(val.end, top.end);
        }
    }

    temp.push_back(val);

    for (int i = 1; i < temp.size(); i++) {
        Interval res;
        res.start = temp[i-1].end;
        res.end = temp[i].start;
        result.push_back(res);
    }
    return result;
}


vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
    vector<vector<int>> event;

    for (int i = 0; i < schedule.size(); i++) {
        for (int j = 0; j < schedule[i].size(); j++) {
            event.push_back({schedule[i][j].start, schedule[i][j].end});
        }
    }

    sort(event.begin(), event.end());
    vector<Interval> result;
    int prevEnd = event[0][1];
    for (int i = 1; i < event.size(); i++) {
        int start = event[i][0];
        prevEnd = max(prevEnd, event[i-1][1]);
        if (prevEnd < start) {
            result.push_back(Interval(prevEnd, start));
        }
    }
    return result;
}