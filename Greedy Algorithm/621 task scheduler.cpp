#include<bits/stdc++.h>
using namespace std;

int leastInterval(vector<char>& tasks, int n) {
    unordered_map<char, int> hmap;
    for (char task: tasks) {
        hmap[task]++;
    }        
    priority_queue<int> pq;

    for (auto m: hmap) {
        pq.push(m.second);
    }
    int count = 0;
    while(!pq.empty()) {
        vector<int> temp;
        for (int i = 0; i < n + 1; i++) {
            if (!pq.empty()) {
                temp.push_back(pq.top());
                pq.pop();
            }
        }
        for (int i = 0; i < temp.size(); i++) {
            if (--temp[i] > 0) {
                pq.push(temp[i]);
            }
        }
        
        count += (pq.empty()) ? temp.size() : n + 1;
    }
    return count;
}

int leastInterval(vector<char>& tasks, int n) {
    vector<int> hmap(26, 0);
    int maxCycle = INT_MIN;
    int siz = tasks.size();
    for (int i = 0; i < tasks.size(); i++) {
        hmap[tasks[i] - 'A']++;
        maxCycle = max(maxCycle, hmap[tasks[i] - 'A']);
    }

    int result = (maxCycle - 1) * (n + 1);

    for (int i = 0; i < 26; i++) {
        if (hmap[i] == maxCycle)
            result++;
    }
    return max(result, siz);
}