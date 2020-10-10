#include<bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& prices) {
  // HOLD[i] = MAX(HOLD[I-1], RESTED[I-1], PRICE[I])
  // SELL[i] = PRICE[I] + HOLD[I-1]
  // RESTED[i] = MAX(RESTED[I-1], SELL[I-1])      
  int n = prices.size();
  if (n == 0) return 0;
  vector<int> hold(n, 0), rested(n, 0), sell(n, 0);
  hold[0] = -prices[0], sell[0] = INT_MIN, rested[0] = 0;
  for (int i = 1; i < n; i++) {
    hold[i] = max(hold[i-1], rested[i-1] - prices[i]);
    sell[i] = prices[i] + hold[i-1];
    rested[i] = max(sell[i-1], rested[i-1]);
  }
  return max(sell[n-1], rested[n-1]);
}