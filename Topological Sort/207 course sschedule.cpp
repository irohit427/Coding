#include<bits/stdc++.h>
using namespace std;


bool canFinish(int n, vector<vector<int>>& prerequisites) {
    vector<int> indegree(n, 0);
    vector<vector<int>> outDegree(n);

    for (auto course: prerequisites) {
        outDegree[course[0]].push_back(course[1]);
        outDegree[course[1]].push_back(course[0]);
        indegree[course[0]]++;
    }

    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0)
            q.push(i);
    }

    int ans = 0;
    while(q.size()) {
        int node = q.front();
        q.pop();
        ans++;

        for (auto course: outDegree[node]) {
            indegree[course]--;
            if (indegree[course] == 0)
                q.push(course);
        }
    }
    return ans == n;
}