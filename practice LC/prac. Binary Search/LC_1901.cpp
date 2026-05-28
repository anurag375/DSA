#include<bits/stdc++.h>	//#include<iostream>
using namespace std;

class Solution {    // 1901. Find a Peak Element II
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        int i=0, j=0;

        while(i<n && j<m){
            int left = (j > 0) ? mat[i][j-1] : -1;
            int right = (j < m-1) ? mat[i][j+1] : -1;
            int top = (i > 0) ? mat[i-1][j] : -1;
            int bottom = (i < n-1) ? mat[i+1][j] : -1;
            
            if(mat[i][j] < left) j--;
            if(mat[i][j] < right) j++;
            if(mat[i][j] < top) i--;
            if(mat[i][j] < bottom) i++;
        }
        return {i, j};
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