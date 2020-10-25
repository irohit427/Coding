#include<bits/stdc++.h>
using namespace std;

vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    
    vector<int> ans;        
    vector<int> indegree(numCourses, 0);
    vector<vector<int>> adj(numCourses, vector<int>());

    for (auto course: prerequisites) {
        adj[course[1]].push_back(course[0]);
        indegree[course[0]]++;
    }

    queue<int> q;

    for (int i: indegree) {
        if (i == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int top = q.front();
        q.pop();
        numCourses--;
        ans.push_back(top);

        for (auto j: adj[top]) {
            if (--indegree[j] == 0) {
                q.push(j);
            }
        }
    }

    return numCourses == 0 ? ans: vector<int>();
}