#include<bits/stdc++.h>
using namespace std;

class Solution {    // 85. Maximal Rectangle

// optimal only:
// t = (m*n) + (n*2n)   [for finding 'prefixSum' + for the task/helper func. below]
// s = (m*n) + n    [for 'prefixSum' + for stack in helper func.]
    int maxAreaHist(vector<int>& heights){
        int n = heights.size();
        int maxArea = 0;
        stack<int> st;  // **U** stores like (modified) next smaller element

        for(int i=0; i<n; i++){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                int tempIdx = st.top();
                st.pop();

                int nse = i;    // (index)
                int pse = (st.empty()) ? -1 : st.top(); // (index)

                int area = heights[tempIdx] * (nse - pse -1);
                maxArea = max(maxArea, area);
            }
            st.push(i);
        }

        // handle remaining stack elements:
        while(!st.empty()){
            int tempIdx = st.top();
            st.pop();

            int nse = n;
            int pse = (st.empty()) ? -1 : st.top();

            int area = heights[tempIdx] * (nse - pse -1);
            maxArea = max(maxArea, area);
        }
        return maxArea;
    }

public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        vector<vector<int>> prefixSum(row, vector<int>(col, 0));  // * 'int' type

        // 1> geneerate "prefixSum" (from top to bottom):
        for(int j=0; j<col; j++){   // *
            int sum = 0;
            for(int i=0; i<row; i++){   // *
                sum += ( matrix[i][j] - '0' );  // *U*
                if(matrix[i][j] == '0') sum = 0;    // *U* ; reset
                prefixSum[i][j] = sum;  
            }
        }
            
        // 2> similar to LC. 84 (but row wise):
        int ansArea = 0;
        for(int i=0; i<row; i++){
            ansArea = max( ansArea, maxAreaHist(prefixSum[i]) );
        }

        return ansArea;
    }
};

int main(){
    Solution sol;
    vector<vector<char>> matrix = {{'1','0','1','0','0'},
                                    {'1','0','1','1','1'},
                                    {'1','1','1','1','1'},
                                    {'1','0','0','1','0'}};     // output: 6
    cout << sol.maximalRectangle(matrix) << endl;
    return 0;
}