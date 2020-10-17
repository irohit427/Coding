#include<bits/stdc++.h>
using namespace std;

int kthSmallest(vector<vector<int>>& matrix, int k) {
    priority_queue<int> pq;

    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            pq.push(matrix[i][j]);
        }
    }        
    int n = matrix.size() * matrix[0].size() - k;
    while(n--) {
        pq.pop();
    }
    return pq.top();
}

int kthSmallest(vector<vector<int>>& matrix, int k) {
    int n=matrix.size();
    int left=matrix[0][0];
    int right = matrix[n-1][n-1];
    while(left<right){
        int mid =(left+right)/2;
        int count=0;
        int row=n-1;
        int col=0;
        while(col<n&&row>=0){
            if(matrix[row][col]<=mid){
                count+=row+1;
                col+=1;
            }else{
                row-=1;
            }
        }
        if(count<k)left=mid+1;
        else right=mid;
    }
    return left;
}