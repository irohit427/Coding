#include<bits/stdc++.h>
using namespace std;

int longestOnes(vector<int>& A, int K) {
    int left = 0, right = 0, noOfZeros = 0, n = A.size();
    if (n == K) return K;
    while(right < n) {
        if (A[right++] == 0)
            noOfZeros++;
        
        if (noOfZeros > K) {
            if (A[left] == 0) {
                noOfZeros--;
            }
            left++;
        } 
    }
    return right - left;
}

int longestOnes(vector<int>& arr, int k) {
    int s = 0, e = 0, fone = 0, fzero = 0;
    int cnt = 0;
    while(e < arr.size()) {
        if (arr[e++]) fone++;
        else fzero++;
        while(fzero > k) {
            if (arr[s++]) fone--;
            else fzero--;
        }
        cnt = max(cnt, fzero + fone);
    } 
    return cnt;
}