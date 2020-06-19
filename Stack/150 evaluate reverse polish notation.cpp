#include<bits/stdc++.h>
using  namespace std;

typedef stack<int> Stack;
int evalRPN(vector<string>& tokens) {
    Stack stk;
    int operand1, operand2, res;
    for (string token: tokens) {
        if (token == "+" || token == "-" || token == "*" || token == "/") {
            operand1 = stk.top();
            stk.pop();
            operand2 = stk.top();
            stk.pop();
            switch(token[0]) {
                case '+':
                    res = operand1 + operand2;
                    stk.push(res);
                    break;
                case '-':
                    res = operand2 - operand1;
                    stk.push(res);
                    break;
                case '*':   
                    res = operand2 * operand1;
                    stk.push(res);
                    break;
                case '/':
                    res = operand2 / operand1;
                    stk.push(res);
                    break;
            }
        } else {
            stk.push(stoi(token));            
        }
    }
    return stk.top();
}