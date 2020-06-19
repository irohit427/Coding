#include<bits/stdc++.h>
using namespace std;

typedef stack<int> Stack;

/**Approach 1*/
string minRemoveToMakeValid(string s) {
    int open = 0;
    string temp;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') open++;
        else if (s[i] == ')') {
            if (open == 0) continue;
            open--;
        }
        temp += s[i];
    }
    
    string ans;
    for (int i = temp.size() - 1; i >= 0; i--) {
        if (temp[i] == '(' && open > 0) {
            open--;
            continue;
        }
        ans += temp[i];
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

/**Approach 2*/
string minRemoveToMakeValid(string s) {
    Stack stk;
    for(int i = 0; i < s.size(); i++) {
        if (s[i] == '(') stk.push(i);
        else if (s[i] == ')') {
            if (!stk.empty()) stk.pop();
            else s[i] = '*';
        }
    }
    while(!stk.empty()) {
        s[stk.top()] = '*';
        stk.pop();
    }
    s.erase(remove(s.begin(), s.end(), '*'), s.end());
    return s;
}