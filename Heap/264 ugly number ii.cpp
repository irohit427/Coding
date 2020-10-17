#include<bits/stdc++.h>
using namespace std;

int nthUglyNumber(int n) {
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(1);
    unordered_set<int> s;        
    s.insert(1);
    while(n--) {
        if (n == 0) {
            return pq.top();
        }

        int a = pq.top();
        pq.pop();

        if (s.find(a * 2) == s.end()) {
            pq.push(2 * a);
            s.insert(2 * a);
        }

        if (s.find(a * 5) == s.end()) {
            pq.push(5 * a);
            s.insert(5 * a);
        }

        if (s.find(a * 3) == s.end()) {
            pq.push(3 * a);
            s.insert(3 * a);
        }
    }
    return 0;
}

int nthUglyNumber(int n) {
    vector<int> dp(n + 1);
    dp[1] = 1;
    int p2 = 1, p3 = 1, p5 = 1;
    for (int i = 2; i <= n; i++) {
        dp[i] = min({dp[p2] * 2, dp[p3] * 3, dp[p5] * 5 });
        if (dp[i] == dp[p2] * 2) p2++;
        if (dp[i] == dp[p3] * 3) p3++;
        if (dp[i] == dp[p5] * 5) p5++;
    }
    return dp[n];
}