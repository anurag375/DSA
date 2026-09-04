#include<bits/stdc++.h>	//#include<iostream>
using namespace std;

class Solution {    // GFG: https://www.geeksforgeeks.org/problems/the-celebrity-problem/1
  public:
    int celebrity(vector<vector<int>>& mat) {
        // brute (my-way):  t = length(cols + rows + cols)    s = 1

        // solution:        [Notice: the column-index filled entirely with 1, CAN be the celebrity.]
            // 1. traverse the cols. of 0th row 
            // 2. if '1' is found, traverse down that col. (all should be 1) ==> if yes, it (say, 'i') might be the celeb 
            // 3. confirm that the found 'i' is actually a celeb ==> Now, traverse the 'i' row. ==> (i==j) should be 1; rest should be 0

        // requirements: 
            // 1. everyone knows (1's) celeb
            // 2. celeb knows nobody except himself (only one 1, rest 0's)
        
        int rows = mat.size(); 
        int cols = mat[0].size();
        
        for(int i=0; i<cols; i++){
            if(mat[0][i] == 1){ // traverse down
                bool isCeleb = true;
                for(int j=0; j<rows; j++){     // all should store 1 here..
                    if(mat[j][i] == 0){
                        isCeleb = false;
                        break;
                    }
                }
                if(isCeleb){    // confirm if the found col (i) is correct: (this rows 'i' should store n-1 0's)
                    for(int j=0; j<cols; j++){
                        if(i == j) continue;
                        if(mat[i][j] == 1) return -1;
                    }
                    
                    return i;   // confirmed celeb..
                }
            }
        }
        
        return -1;
    }
};

int main(){
    Solution sol;
    // vector<vector<int>> mat = {{1,0,1},     // Output: -1
    //                            {0,1,1}, 
    //                            {1,0,1}};
    vector<vector<int>> mat = {{1,0,1},     // Output: 2
                               {0,1,1}, 
                               {0,0,1}};
    cout << sol.celebrity(mat) << endl;
    
    return 0;
}