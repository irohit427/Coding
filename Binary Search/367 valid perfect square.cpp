#include<bits/stdc++.h>
using namespace std;

bool isPerfectSquare(int num) {
    int squareRoot = floor(sqrt(num));
    if (squareRoot*squareRoot == num) return true;
    return false;
}