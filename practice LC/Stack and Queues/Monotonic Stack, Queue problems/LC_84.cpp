#include<bits/stdc++.h>	//#include<iostream>
using namespace std;

class Solution {    // 84. Largest Rectangle in Histogram
public:
    int largestRectangleArea(vector<int>& heights) {
    // striver-way:      ==>     
        int n = heights.size();
        int maxArea = 0;
        
        for(int i=0; i<n; i++){
            int currHeight = heights[i];
            int currArea;
            int j = i;
            while(j<n && heights[j] >= currHeight){
                currArea = (j - i + 1) * currHeight;
                maxArea = max(maxArea, currArea);
                j++;
            }
        }
        return maxArea;   
    }
};

int main(){
    Solution sol;
    vector<int> heights = {2,1,5,6,2,3};     // output: 10
    cout << sol.largestRectangleArea(heights) << endl;
    return 0;
}


    // brute (my-way):      ==>     TLE
        // int n = heights.size();
        // int maxArea = 0;
        
        // for(int i=0; i<n; i++){
        //     for(int j=i; j<n; j++){
        //         int minHeight = *min_element(heights.begin()+i, heights.begin()+j+1);
        //         maxArea = max(maxArea, minHeight * (j-i+1));
        //     }
        // }
        // return maxArea; 