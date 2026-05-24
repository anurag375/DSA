#include<bits/stdc++.h>	//#include<iostream>
using namespace std;

class Solution {    // 74. Search a 2D Matrix
public:
// optimal: binary search:  t = log(m*n) 
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();    // row_len
        int n = matrix[0].size(); // col_len

        int low = 0;
        int high = m*n - 1; // *U* -1 must be there for proper search range
        while(low <= high){
            int mid = low + (high-low)/2;
            int curr_num = matrix[mid/n][mid%n];    // **U**

            if(curr_num == target) return true;
            else if(curr_num < target) low = mid + 1;
            else high = mid - 1;
        }
        return false;
    }
};

int main(){
    Solution sol;
    vector<vector<int>> matrix = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    int target = 3;
    cout << sol.searchMatrix(matrix, target) << endl;
    
    return 0;
}


// brute: (search every element) t = m*n

// better: (apply binary search on each row) t = row * log (col)