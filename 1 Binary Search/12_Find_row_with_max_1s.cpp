#include<bits/stdc++.h>	//#include<iostream>
using namespace std;

class Solution {
// optimal:     t = n log(m)
    int BS(vector < vector < int >> & mat, int i, int m){   // **U** you can also use Lower Bound/Upper Bound/First Occurrence
        int low = 0, high = m-1;

        while (low <= high){
            int mid = low + (high-low)/2;

            if(mat[i][mid] == 1){   // or if(mat[i][mid] >= 1)
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return low; // stores the first index from where 1s start
    }

    public:   
    int rowWithMax1s(vector < vector < int >> & mat) {
    // brute:       t = n * m
        int n = mat.size(); 
        int m = mat[0].size(); 
        int max_cnt = 0;
        int max_idx = -1;

        for(int i=0; i<n; i++){

            int start_idx = BS(mat, i, m);
            int cnt = m - start_idx; // gives count of 1s in the current row

            if(cnt > max_cnt){
                max_cnt = cnt;
                max_idx = i;
            }
        }

        return max_idx;
    }
};

int main(){
    Solution obj;
    // vector<vector<int>> a = {{1,1,1}, {0,0,1}, {0,0,0}};
    vector<vector<int>> a = {{0,0}, {0,0}, {0,0}};

    int result = obj.rowWithMax1s(a);
    cout << result << endl;    
    return 0;
}


    // brute: (simple iterative search)       t = n * m
        // int n = mat.size(); 
        // int m = mat[0].size(); 
        // int max_cnt = 0;
        // int max_idx = -1;

        // for(int i=0; i<n; i++){
        //     int cnt = 0;
        //     for(int j=0; j<m; j++){
        //         // if(mat[i][j] == 1)   //  **U** NO need for this (because there are only 0s and 1s)
        //             cnt++;
        //     }
        //     if(cnt > max_cnt){
        //         max_cnt = cnt;
        //         max_idx = i;
        //     }
        // }

        // return max_idx;