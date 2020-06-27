#include<bits/stdc++.h>
using namespace std;

typedef stack<int> Stack;
int calculate (string s) {
    Stack stk;
    int result = 0, sign = 1, number = 0;

    for (int i = 0; i < s.length(); i++) {
        if (isdigit(s[i])) {
            // get number
            number = number * 10 + (s[i] - '0');
        } else if (s[i] == '+' || s[i] == '-') {
            result += number * sign;
            sign = s[i] == '+' ? 1: -1;
            number = 0;                     // reset number
        } else if (s[i] == '(') {
            stk.push(result);               // push result and sign and reset them
            stk.push(sign);
            result = 0;
            sign = 1;
        } else if (s[i] == ')') {
            result += number * sign;        // pop sign and number and add it to result
            result *= stk.top();    stk.pop();
            result += stk.top();    stk.pop();
            number = 0;
        }
    }
    if (number != 0) {
        result += number * sign;
    }
    return result;
}