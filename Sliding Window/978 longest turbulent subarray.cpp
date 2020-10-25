#include<bits/stdc++.h>
using namespace std;

int compare(int a, int b) {
    if (a > b) 
        return 1;
    else if (a < b)
        return -1;
    return 0;
}
int maxTurbulenceSize(vector<int>& A) {

    int ans = 1;
    int left = 0;
    for (int i = 1; i < A.size(); i++) {
        int c = compare(A[i-1], A[i]);
        if (c == 0)
            left = i;
        else if (i == A.size() - 1 || c * compare(A[i], A[i + 1]) != -1) {
            ans = max(ans, i - left + 1);
            left = i;
        }
    }
    return ans;
}