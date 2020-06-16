#include<bits/stdc++.h>
using namespace std;

typedef map<char, int> Map;
typedef stack<char> Stack;
string removeDuplicateLetters(string s) {
    Stack stk;
        Map count;
        for (char ch: s) count[ch]++;
        vector<bool> visited(26, false);
        char top;
        string res = "";
        for (char ch: s) {
            count[ch]--;
            if (visited[ch-'a']) continue;
            while(!stk.empty() && ch < stk.top() && count[stk.top()] != 0) {
                top = stk.top();
                stk.pop();
                visited[top-'a'] = false;
            }
            stk.push(ch);
            visited[ch-'a'] = true;
        }

        while(!stk.empty()) {
            res = stk.top() + res;
            stk.pop();
        }
        return res;
}