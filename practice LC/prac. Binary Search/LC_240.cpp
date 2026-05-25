#include<bits/stdc++.h>	//#include<iostream>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
    // OPTIMAL: (NO direct binary search)  t = m + n
        int n = matrix.size();
        int m = matrix[0].size();
        int i = 0;
        int j = m - 1;

        while (i<=n-1 && j>=0)
        {
            if(matrix[i][j] == target) return true;
            else if(matrix[i][j] < target) i++;
            else j--;   // (matrix[i][j] > target)
        }
        
        return false;
    }
};

int main(){
    Solution obj;
    vector<vector<int>> a = {{1,4,7,11,15}, {2,5,8,12,19}, {3,6,9,16,22}, {10,13,14,17,24}, {18,21,23,26,30}};
    int target = 5;

    bool result = obj.searchMatrix(a, target);
    cout << result << endl;
    return 0;
}


// brute: (search every element) t = m*n    ==> same as LC_74.cpp

// better: (apply binary search on each row) t = row * log (col)    ==>   same as LC_74.cpp