#include<bits/stdc++.h>
using namespace std;

typedef map<string, int> Map;
typedef stack<Map> Stack;
string countOfAtoms(string formula) {
    int n = formula.length();
    Stack stk;
    Map curr;
    for (int i = 0; i < n; i++) {

        if (formula[i] == '(') {
            stk.push(curr);
            curr.clear();
        } else if (formula[i] == ')') {
            Map prev = curr;
            int valency = i + 1, no_of_attom;
            while (valency < n && isdigit(formula[valency])) {
                valency++;
            }
            if (valency == i + 1) {
                no_of_attom = 1;
            } else {
                no_of_attom = stoi(formula.substr(i+1, valency - (i + 1)));
            }
            curr = stk.top();
            stk.pop();
            for (auto e: prev) {
                curr[e.first] += e.second*no_of_attom;
            }
            i = valency - 1;

        } else if (formula[i] >= 'A' && formula[i] <= 'Z') {
            int index = i+1;
            while (index < n && formula[index] >= 'a' && formula[index] <= 'z') {
                index++;
            }
            string element = formula.substr(i, index - i);
            int valency = index, no_of_attom;
            while(valency < formula.size() && isdigit(formula[valency]))    valency++;
            if (index == valency)   no_of_attom = 1;
            else no_of_attom = stoi(formula.substr(index, valency - index));
            curr[element] += no_of_attom;
            i = valency - 1;
        }
    }
    
    string result = "";
    for (auto e: curr) {
        result += e.first;
        if (e.second > 1) {
            result += "" + e.second;
        }
    }
    return result;
}