#include<bits/stdc++.h>	//#include<iostream>
using namespace std;


class Solution {    // LC 34: Find First and Last Position of Element in Sorted Array

    public:
    vector<int> searchRange(vector<int>& nums, int target) {

    // practice (even easier than the optimal)   t = log n
        int n = nums.size();
        int floor_idx = -1, ceil_idx = -1;

        // find ceil idx (modified Lower Bound), ==> ***U*** ONLY for ceil INDEX (NOT for VALUE)
        int low = 0, high = n-1;
        while(low <= high){
            int mid = low + (high-low)/2;

            if(nums[mid] <= target){
                ceil_idx = mid;
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }

        // NOT found: 
        if(ceil_idx == -1 || nums[ceil_idx] != target) return {-1, -1}; 
        // *U* 1st cond. is for: [for target smaller than every element] & [empty array]  
        
        // find floor idx (Lower Bound), ==> ***U*** ONLY for floor INDEX (NOT for VALUE)
        low = 0, high = n-1;
        while(low <= high){
            int mid = low + (high-low)/2;

            if(nums[mid] >= target){
                floor_idx = mid;
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }

        return {floor_idx, ceil_idx};
    }
};

int main(){
    vector<int> nums = {1,2,3,4};
    int target = 0;

    Solution obj;
    vector<int> ans = obj.searchRange(nums, target);

    cout << ans[0] << "," << ans[1];

    return 0;
}