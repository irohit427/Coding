#include<bits/stdc++.h>
using namespace std;

typedef stack<char> Stack;

bool isValid(string s) {
    Stack stk;
    for (auto ch: s) {
        if (ch == '(' || ch == '[' || ch == '{') stk.push(ch);
        else {
            if (stk.empty()) return false;
            if ( (ch == ')' && stk.top() != '(') || (ch == '}' && stk.top() != '{') || (ch == ']' && stk.top() != '['))
            return false;
            stk.pop();
        }
    }
    if (!stk.empty()) return false;
    return true;
}