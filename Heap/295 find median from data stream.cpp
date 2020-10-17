#include<bits/stdc++.h>
using namespace std;

priority_queue<int> maxHeap;
priority_queue<int, vector<int>, greater<int>> minHeap;
    
void addNum(int num) {
    if (maxHeap.empty()) {
        maxHeap.push(num);
    } else {
        if (num > maxHeap.top())
            minHeap.push(num);
        else
            maxHeap.push(num);
        
        while(maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }

        while(maxHeap.size() < minHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
}

double findMedian() {
    if (maxHeap.size() == minHeap.size()) {
        return (maxHeap.top() + minHeap.top()) / 2.0;
    }   
    return maxHeap.top();
}