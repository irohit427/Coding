#include<bits/stdc++.h>
using namespace std;

int numKLenSubstrNoRepeats(string S, int K) {
    int map[26] = {0};
    int noOfDuplicates = 0;
    int n = S.length();
    if (n < K) return 0;

    for (int i = 0; i < K; i++) {
        if (map[S[i] - 'a'] == 1) {
            noOfDuplicates++;
        }
        map[S[i] - 'a']++;
    }
    int count = 0;
    for (int i = K; i < n; i++) {
        if (noOfDuplicates == 0)    count++;

        map[S[i-K] - 'a']--;

        if (map[S[i-K] - 'a'] == 1)
            noOfDuplicates--;
        
        if (map[S[i] - 'a'] == 1)
            noOfDuplicates++;
        
        map[S[i] - 'a']++;
    }
    if (noOfDuplicates == 0)
        count++;
    return count;
}