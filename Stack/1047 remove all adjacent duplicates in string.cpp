#include<bits/stdc++.h>
using namespace std;

typedef stack<char> Stack;
string removeDuplicates(string s) {
    int i = 0;
    Stack stk;
    string res = "";
    while(i < s.size()) {
        if (stk.empty() || stk.top() != s[i]) stk.push(s[i]);
        else stk.pop();
        i++;
    }
    while(!stk.empty()) { 
        res = stk.top() + res;
        stk.pop();
    }
    return res;
}