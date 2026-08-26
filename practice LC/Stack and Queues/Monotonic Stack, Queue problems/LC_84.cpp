#include<bits/stdc++.h>
using namespace std;

class Solution {    // 84. Largest Rectangle in Histogram
    public:
    int largestRectangleArea(vector<int>& heights) {

    // optimal: [push in stack (left to right) -> caculate area while poping (right to left)]
    // t = n + n = n [for traversal (and pushing to stack) + for poping from stack]
    // s = n
        int n = heights.size();
        stack<int> st;  // stores similar to the "find smaller element" stack
        int maxArea = 0;

        for(int i=0; i<n; i++){
            while(!st.empty() && heights[st.top()] >= heights[i]){ // perform..
                int temp = st.top();    // (index)
                st.pop();

                int nse = i;   // next smaller element (index)
                int pse = (st.empty()) ? -1 : st.top();   // previous smaller element (index)

                int area = heights[temp] * (nse - pse -1);
                maxArea = max(maxArea, area);
            }
            st.push(i); 
        }

        // handle leftover stack elements [all are arranged in increasing heights]:
        while(!st.empty()){
            int temp = st.top();
            st.pop();
            int nse = n;
            int pse = (st.empty()) ? -1 : st.top();

            int area = heights[temp] * (nse - pse -1);
            maxArea = max(maxArea, area);
        }

        return maxArea;  
    }
};

int main(){
    Solution sol;
    vector<int> heights = {2,1,5,6,2,3};     // output: 10
    // vector<int> heights = {2,4};     // output: 4
    cout << sol.largestRectangleArea(heights) << endl;
    return 0;
}


// brute (striver-way): [precompute PSE, NSE]       ==>     Accepted..
// t = 2*2n + n = 5n = n  [for both helper functions + loop in the main funstion]
// s = 2*2n = 4n = n  [for both helper funstions]
    // vector<int> findPSE(vector<int>& heights){
    //     int n = heights.size();
    //     stack<int> st;
    //     vector<int> pse;

    //     for(int i=0; i<n; i++){
    //         while(!st.empty() && heights[st.top()] >= heights[i])   // **U**
    //             st.pop();
    //         if(!st.empty()) pse.push_back(st.top());   // *U* store indices
    //         else pse.push_back(-1);     // Not found..
    //         st.push(i);
    //     }
    //     return pse;
    // }
        
    // vector<int> findNSE(vector<int>& heights){
    //     int n = heights.size();
    //     stack<int> st;
    //     vector<int> nse(n);

    //     for(int i=n-1; i>=0; i--){
    //         while(!st.empty() && heights[st.top()] >= heights[i])   // **U**
    //             st.pop();
    //         if(!st.empty()) nse[i] = st.top(); // *U* store indices
    //         else nse[i] = n;     // Not found..
    //         st.push(i);
    //     }
    //     return nse;
    // }


// =============


    // brute (my-way):  [find subarrays -> find smallest height -> calc. current area -> shortlist maxArea]    ==>     TLE
        // int n = heights.size();
        // int maxArea = 0;
        
        // for(int i=0; i<n; i++){
        //     for(int j=i; j<n; j++){
        //         int minHeight = *min_element(heights.begin()+i, heights.begin()+j+1);
        //         maxArea = max(maxArea, minHeight * (j-i+1));
        //     }
        // }
        // return maxArea; 