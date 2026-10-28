#include<bits/stdc++.h>
using namespace std;

class Solution {    // 54. Spiral Matrix
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
    // retry: (only optimal)
        vector<int> ans;

        int top = 0, bottom = matrix.size() - 1;    // tracks indices
        int left = 0, right = matrix[0].size() - 1;    // tracks indices

        while(top <= bottom && left <= right){
            // print top:
            for(int i=left; i<=right; i++)
                ans.push_back(matrix[top][i]);
            top++;

            // print right:
            for(int i=top; i<=bottom; i++)
                ans.push_back(matrix[i][right]);
            right--;

            // print bottom:
            if(top <= bottom){  // **U** prevents horizontal repetition (backwards)
                for(int i=right; i>=left; i--)
                    ans.push_back(matrix[bottom][i]);
                bottom--;
            }

            // print left:
            if(left <= right){  // **U** prevents vertical repetition (backwards)
                for(int i=bottom; i>=top; i--)
                    ans.push_back(matrix[i][left]);
                left++;
            }
        }

        return ans;
    }
};

int main(){
    Solution sol;
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};  // output: [1,2,3,6,9,8,7,4,5]
    vector<int> ans = sol.spiralOrder(matrix);
    for(int num:ans) cout << num << " ";
    return 0;
}

    // only OPTIMAL:
        // int m = matrix.size();
        // int n = matrix[0].size();

        // // indexes:
        // int top = 0;
        // int bottom = m - 1;
        // int left = 0;
        // int right = n - 1;

        // vector<int> ans;

        // while(top <= bottom && left <= right){  // My Way...

        //     for(int j=left; j<=right; j++){
        //         ans.push_back(matrix[top][j]);
        //     }
            
        //     for(int i=top+1; i<=bottom; i++){
        //         ans.push_back(matrix[i][right]);
        //     }


        //     // if(top < bottom){
        //     if(top+1 <= bottom){  // *** imp to avoid reverse row tracing in single line/row matrix
        //         for(int j=right-1; j>=left; j--){
        //             ans.push_back(matrix[bottom][j]);
        //         }
        //     }


        //     // if(left < right){  
        //     if(left <= right-1){  // *** imp to avoid last element 
        //         for(int i=bottom-1; i>=top+1; i--){
        //             ans.push_back(matrix[i][left]);
        //         }
        //     }

        //     top++;
        //     bottom--;
        //     left++;
        //     right--;
                
        // }

        // return ans;