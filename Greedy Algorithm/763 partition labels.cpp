#include<bits/stdc++.h>
using namespace std;

vector<int> partitionLabels(string S) {
    int n = S.length();
    unordered_map<char, int> hmap;
    for (int i = 0; i < n; i++) {
        hmap[S[i]] = max(hmap[S[i]], i);
    }        

    vector<int> ans;
    int maxIndex = -1, prev = -1;
    for (int i = 0; i < n; i++) {
        maxIndex = max(maxIndex, hmap[S[i]]);

        if (maxIndex == i) {
            ans.push_back(i - prev);
            prev = maxIndex;
        }
    }
    return ans;
}