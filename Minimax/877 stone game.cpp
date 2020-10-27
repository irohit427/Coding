#include<bits/stdc++.h>
using namespace std;

bool stoneGame(vector<int>& piles) {
    int n = piles.size();
    if (n == 2) 
        return true;

    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += piles[i];
    }

    int i = (n/2) - 1;
    int j = i + 1;
    int alexScore = 0;
    while (i >= 0 && j < n) {
        if (piles[i] > piles[j]) {
            alexScore += piles[i];
        } else {
            alexScore += piles[j];
        }
        i--;
        j++;
        if (alexScore > sum / 2)
            return true;
    }
    return false;
}