#include<bits/stdc++.h>
using namespace std;

int atMostK(vector<int>& A, int K) {
    int left = 0, right = 0, n = A.size(), ans = 0;
    unordered_map<int, int> m;

    for (right; right < n; right++) {
        m[A[right]]++;
        if (m[A[right]] == 1) {
            K--;
        }

        while(K < 0) {
            if (--m[A[left]] == 0) K++;
            left++;
        }
        ans += right - left + 1;
    }
    return ans;
}

int subarraysWithKDistinct(vector<int>& A, int K) {
    return atMostK(A, K) - atMostK(A, K - 1);        
}