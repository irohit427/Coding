#include<bits/stdc++.h>
using namespace std;

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int tank, start = 0, sum = INT_MAX;

    for (int i = 0; i < gas.size(); i++) {
        tank += gas[i] - cost[i];
        if (tank < sum) {
            sum = tank;
            start = i + 1;
        }
    }
    return tank < 0 ? -1 : (start % gas.size());
}