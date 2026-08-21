#include<bits/stdc++.h>	//#include<iostream>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
    // brute (little better T.C & S.C):   t = 2n = n      s = n   [skipped the prefixMax -> in the last loop, remember the left-max]
        int n = height.size();
        int leftMax = height[0];    // replacement of prefixMax vector
        vector<int> suffixMax(n,0);
        int totalWater = 0;

        // 1> find suffixMax (finds taller bars on right side):
        suffixMax[n-1] = height[n-1];
        for(int i=n-2; i>=0; i--){
            suffixMax[i] = max(suffixMax[i+1], height[i]);
        }

        // 2> find water:
        for(int i=0; i<n; i++){
            leftMax = max(leftMax, height[i]);

            int waterHeight = min(leftMax, suffixMax[i]); // *U* water level above the current bar..
            totalWater += waterHeight - height[i];
        }

        return totalWater;
    }
};

int main(){
    Solution sol;
    // vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};     // output: 6
    vector<int> height = {4,2,0,3,2,5};     // output: 9
    cout << sol.trap(height) << endl;
    return 0;
}



    // brute (little better T.C & S.C):   t = 2n = n      s = n  
    // [mostly same as brute]  ==>  [skip the "prefixMax" -> maintain a "leftMax" (int) in the final loop]

        // int n = height.size();
        // int leftMax = height[0];    // replacement of the prefixMax vector
        // vector<int> suffixMax(n,0);
        // int totalWater = 0;

        // // 1> find suffixMax (finds taller bars on right side):
        // suffixMax[n-1] = height[n-1];
        // for(int i=n-2; i>=0; i--){
        //     suffixMax[i] = max(suffixMax[i+1], height[i]);
        // }

        // // 2> find water:
        // for(int i=0; i<n; i++){
        //     leftMax = max(leftMax, height[i]);

        //     int waterHeight = min(leftMax, suffixMax[i]); // *U* water level above the current bar..
        //     totalWater += waterHeight - height[i];
        // }

        // return totalWater;




    // brute:   t = 3n = n      s = 2n = n
        // int n = height.size();
        // vector<int> prefixMax(n,0);
        // vector<int> suffixMax(n,0);
        // int totalWater = 0;

        // // 1> find prefixMax and suffixMax (finds taller bars on either sides):
        // prefixMax[0] = height[0];
        // for(int i=1; i<n; i++){
        //     prefixMax[i] = max(prefixMax[i-1], height[i]);
        // }
        // suffixMax[n-1] = height[n-1];
        // for(int i=n-2; i>=0; i--){
        //     suffixMax[i] = max(suffixMax[i+1], height[i]);
        // }

        // // 2> find water:
        // for(int i=0; i<n; i++){
        //     int waterHeight = min(prefixMax[i], suffixMax[i]); // *U* water level above the current bar..
        //     totalWater += waterHeight - height[i];
        // }

        // return totalWater;