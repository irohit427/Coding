#include<bits/stdc++.h>
using namespace std;

static bool compare(const vector<int>& a,const vector<int>& b) {
    return a[1] < b[1];
}

int find(int x, vector<int> f) {
    if (f[x] == x)
        return x;
    else 
        f[x] = find(f[x], f);
}

int maxEvents(vector<vector<int>>& events) {
    sort(events.begin(), events.end(), compare);
    vector<int> f;

    int m = events[events.size() - 1][1];

    for (int i = 0; i <= m + 1; i++) {
        f.push_back(i);
    }

    int ans = 0;

    for (auto event: events) {
        int x = find(event[0], f);
        if (x <= events[1]) {
            ans++;
            f[x] = find(x + 1, f);
        }
    }
    return ans;
}
