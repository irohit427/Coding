#include<bits/stdc++.h>
using namespace std;

int mySqrt(int x) {
    if (x == 0 || x == 1) return x;
    int l = 0, r = ceil(x/2), mid;
    while(l <= r) {
        mid = l + (r - l) / 2;
        long long sq = mid * mid;
        if (sq <= x)
            l = mid + 1;
        else 
            r = mid - 1;
    }
    return l - 1;
}