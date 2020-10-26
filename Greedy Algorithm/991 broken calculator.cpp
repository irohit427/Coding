#include<bits/stdc++.h>
using namespace std;

int brokenCalc(int X, int Y) {
    int count = 0;
    while(Y > X) {
        if (Y % 2 != 0) {
            Y++;
        } else {
            Y = Y / 2;
        }
        count++;
    }        
    count += (X-Y);
    return count;
}