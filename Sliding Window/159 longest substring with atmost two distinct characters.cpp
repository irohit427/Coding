#include<bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstringTwoDistinct(string s) {
    unordered_map<char, int> count;
    int right = 0, left = 0;
    for (; right < s.length(); right++) {
        count[s[right]]++;

        if (count.size() > 2) {
            count[s[left]]--;
            if (count[s[left]] == 0) 
                count.erase(s[left]);
            left++;
        }
    }
    return right - left;
}