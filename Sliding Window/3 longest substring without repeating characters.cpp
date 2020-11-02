#include<bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s) {
    int maxLength = 0;
    int start = 0, end = 0;
    map<char, int> m;
    while(end < s.length()) {
        char ch = s[end];
        if (m.count(ch) && m[ch] >= start) {
            maxLength = max(maxLength, end - start);
            start = m[ch] + 1;
        }
        m[ch] = end++; 
    }   
    return max(maxLength, end - start);
}