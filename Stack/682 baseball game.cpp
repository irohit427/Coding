#include<bits/stdc++.h>
using namespace std;

typedef stack<int> Stack;
int calPoints(vector<string>& ops) {
    Stack stk;
    int sum = 0, n1, n2;
    for (auto op: ops) {
        if (op == "D") {
            sum += stk.top() * 2;
            stk.push(stk.top() * 2);
        } else if (op == "C") {
            sum -= stk.top();
            stk.pop();
        } else if (op == "+") {
            n2 = stk.top();
            stk.pop();
            n1 = stk.top();
            sum += (n1 + n2);
            stk.push(n2);
            stk.push(n1 + n2);
        } else {
            stk.push(stoi(op));
            sum += stoi(op);
        }
    }
    return sum;
}