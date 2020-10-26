#include<bits/stdc++.h>
using namespace std;

string reorganizeString(string S) {
    vector<int> count(26, 0);
    string ans = "";
    priority_queue<pair<int, char>> pq;
    for (char ch: S) {
        count[ch - 'a']++;
    }
    for (int i = 0; i < 26; i++) {
        if (count[i] != 0) {
            pq.push({count[i], (char)('a' + i)});
        } 
    }

    while (pq.size() > 1) {
        auto a = pq.top();
        pq.pop();
        auto b = pq.top();
        pq.pop();

        ans += a.second;
        ans += b.second;

        a.first--;
        b.first--;

        if (a.first > 0) {
            pq.push(a);
        }

        if (b.first > 0) {
            pq.push(b);
        }
    }

    if (pq.empty())
        return ans;
    
    if (pq.top().first > 1)
        return "";
    else
        ans.push_back(pq.top().second);
    return ans;
}