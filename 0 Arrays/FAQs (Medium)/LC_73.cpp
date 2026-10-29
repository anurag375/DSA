#include<bits/stdc++.h>
using namespace std;

class Solution {    // 73. Set Matrix Zeroes
public:
    void setZeroes(vector<vector<int>>& matrix) {
    // Better:  t = O(3*m*n) = O(m*n)    s = O(m+n)
        int n = matrix.size();  // rows
        int m = matrix[0].size();  // cols

        // (for tracking positions):
        vector<int> rows(n, 1);
        vector<int> cols(m, 1);

        // 1> mark rows with zeros: (lets say, with "0")
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j] == 0){
                    rows[i] = 0;
                    break;
                }
            }
        }

        // 2> mark cols with zeros: (with the same "0")
        for(int j=0; j<m; j++){
            for(int i=0; i<n; i++){
                if(matrix[i][j] == 0){
                    cols[j] = 0;
                    break;
                }
            }
        }

        // 3> change original matrix:
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(rows[i] == 0 || cols[j] == 0) 
                    matrix[i][j] = 0;
            }
        }

    }
};

int main(){
    Solution sol;
    vector<vector<int>> matrix = {{1,1,1},{1,0,1},{1,1,1}};  // output: [[1,0,1],[0,0,0],[1,0,1]]
    sol.setZeroes(matrix);
    for(auto row:matrix){
        for(int x:row) cout << x << " ";
        cout << endl;
    }
    return 0;
}

// [optimal one is hard..]

// BRUTE: will not work:
    // void setRow(int i, int n, vector<vector<int>>& matrix){
    //     for(int j=0; j<n; j++){
    //         if(matrix[i][j] != 0)   // **** don't change the original 0's...
    //             matrix[i][j] = -1;
    //     }
    // }
    
    // void setCol(int j, int m, vector<vector<int>>& matrix){
    //     for(int i=0; i<m; i++){
    //         if(matrix[i][j] != 0) 
    //             matrix[i][j] = -1;
    //     }
    // }

    // void setZeroes(vector<vector<int>>& matrix) {
    //     int m = matrix.size();
    //     int n = matrix[0].size();
    //     for(int i=0; i<m; i++){
    //         for(int j=0; j<n; j++){
    //             if(matrix[i][j]==0){    // *** first turn to -1 --> then to 0
    //                 setRow(i, n, matrix);
    //                 setCol(j, m, matrix);
    //             }
    //         }
    //     }
        
    //     for(int i=0; i<m; i++){
    //         for(int j=0; j<n; j++){
    //             if(matrix[i][j]==-1){
    //                 matrix[i][j] = 0;
    //             }
    //         }
    //     }



    // }

