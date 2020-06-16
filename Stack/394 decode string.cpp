#include<bits/stdc++.h>
using namespace std;

typedef stack<int> Stack;
string decode(string s, int n) {
    string res = "";
    for (int i = 0; i < n ; i++) {
        res += s;
    }
    return res;
}

string decodeString(string s) {
    
    Stack stk;
    stack<string> resStack;
    int i = 0, n = s.size();
    string res = "";
    while( i < n ) {
        if (isdigit(s[i])) {
            int count = 0 ;
            while(isdigit(s[i])) {
                count = count * 10 + (s[i] - '0');
                i++;
            }
            stk.push(count);
        } else if (s[i] == '[') {
            resStack.push(res);
            res = "";
            i++;
        } else if (s[i] == ']') {
            string temp = resStack.top();
            resStack.pop();
            res = decode(temp, stk.top());
            stk.pop();
            i++;
        } else {
            res += s[i++];
        }
    }
    return res;
}