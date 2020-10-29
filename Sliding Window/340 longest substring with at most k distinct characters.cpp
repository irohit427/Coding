#include<bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstringKDistinct(string s, int k) {
    int ans = 0;

    unordered_map<char, int> m;
    int left = 0, right = 0, n = s.length();
    for (right; right < n; right++) {

        m[s[right]]++;

        while (m.size() > k) {
            if (--m[s[left]] == 0) m.erase(s[left]);
            left++;
        }
        ans = max(ans, right - left + 1);
    }       
    return ans;
}