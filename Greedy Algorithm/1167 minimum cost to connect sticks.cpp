#include<bits/stdc++.h>
using namespace std;

int connectSticks(vector<int>& sticks) {
    priority_queue<int, vector<int>, greater<int>> pq(sticks.begin(), sticks.end());
    int total = 0, result;
    while(pq.size() > 1) {
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        result = a + b;
        total += result;
        pq.push(result);
    }     
    return total;
}