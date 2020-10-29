#include<bits/stdc++.h>
using namespace std;

int characterReplacement(string s, int k) {
    int left = 0, right = 0, n = s.length(), count = 0, maxLength = 0;
    unordered_map<char, int> m;

    for (right; right < n; right++) {
        m[s[right]]++;

        count = max(count, m[s[right]]);

        if (right - left + 1 - count > k) {
            m[s[left]]--;
            left++;
        }
        maxLength = max(maxLength, right - left + 1);
    }   
    return maxLength;     
}