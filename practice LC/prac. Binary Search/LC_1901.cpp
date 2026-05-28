#include<bits/stdc++.h>	//#include<iostream>
using namespace std;

class Solution {    // 1901. Find a Peak Element II
public:
// optimal:    t = n * log(m)   ==> n = rows, m = col.s
    int findColMax(vector<vector<int>>& mat, int col, int n){    // col = mid
        int maxNum = -1;
        int maxRowIdx = -1;
        for(int i=0; i<n; i++){
            if(maxNum < mat[i][col]){
                maxNum = mat[i][col];
                maxRowIdx = i;
            }
        }
        return maxRowIdx;
    }

    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        int low = 0;
        int high = m - 1;

        while(low <= high){
            int mid = low + (high-low)/2;   // *U* stores the col. index
            int maxRowIdx = findColMax(mat, mid, n);  // *U* stores the row index

            int left = (mid > 0) ? mat[maxRowIdx][mid-1] : -1;
            int right = (mid < m-1) ? mat[maxRowIdx][mid+1] : -1;

            if(left < mat[maxRowIdx][mid] && mat[maxRowIdx][mid] > right) return{maxRowIdx, mid};
            else if(left > mat[maxRowIdx][mid]) high = mid - 1;
            else low = mid + 1;
        }

        return {-1, -1};    // default.. will never run as per the test cases
    }
};

int main(){
    Solution obj;
    vector<vector<int>> mat = {{1,4},{3,2}};
    vector<int> result = obj.findPeakGrid(mat);
    for(int i=0; i<result.size(); i++){
        cout << result[i] << " ";
    }
    
    return 0;
}


    // my-way (another) brute:    t = n * m
        // int n = mat.size();
        // int m = mat[0].size();

        // int i = 0, j = 0;

        // while(i<n && j<m){
        //     int left = (j > 0) ? mat[i][j-1] : -1;
        //     int right = (j < m-1) ? mat[i][j+1] : -1;
        //     int top = (i > 0) ? mat[i-1][j] : -1;
        //     int bottom = (i < n-1) ? mat[i+1][j] : -1;
            
        //     if(mat[i][j] < left) j--;
        //     else if(mat[i][j] < right) j++;
        //     else if(mat[i][j] < top) i--;
        //     else if(mat[i][j] < bottom) i++;
        //     else return {i, j};     // ans..
        // }
        // return {-1, -1};    // default..



    // my-way brute:    t = n * m
        // int n = mat.size();
        // int m = mat[0].size();

        // for(int i=0; i<n; i++){   // works for 3x3 matrix or more..
        //     for(int j=0; j<m; j++){
        //         int left = (j > 0) ? mat[i][j-1] : -1;
        //         int right = (j < m-1) ? mat[i][j+1] : -1;
        //         int top = (i > 0) ? mat[i-1][j] : -1;
        //         int bottom = (i < n-1) ? mat[i+1][j] : -1;

        //         if(mat[i][j] > left && mat[i][j] > right && mat[i][j] > top && mat[i][j] > bottom) return vector<int> {i,j};                
        //     }
        // }
        // return {-1, -1}; // default..