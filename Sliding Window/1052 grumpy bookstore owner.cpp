#include<bits/stdc++.h>
using namespace std;

int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
    int sum = 0, maxSum = 0, total = 0;

    for (int i = 0; i < customers.size(); i++) {

        if (i - X >= 0 && grumpy[i - X] == 1) {
            sum -= customers[i-X];
        }
        
        if (grumpy[i] == 1) 
            sum += customers[i];
        else
            total += customers[i];
        
        maxSum = max(maxSum, sum);

    }
    return maxSum + total;
}