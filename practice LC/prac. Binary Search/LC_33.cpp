#include<bits/stdc++.h>	//#include<iostream>
using namespace std;


class Solution {    // LeetCode: 33 => Search in Rotated Sorted Array 1

public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n - 1;

        while(low <= high){
            int mid = low + (high-low)/2;

            if(nums[mid] == target) return mid;

            else if(nums[low] <= nums[mid]){    
                if(nums[low] <= target && target <= nums[mid]) high = mid - 1;
                else low = mid + 1;
            }

            else if(nums[mid] <= nums[high]){
            // or else{
                if(nums[mid] <= target && target <= nums[high]) low = mid + 1;
                else high = mid - 1;
            }
        }

        return -1;  // not found
    }
};


int main(){
    vector<int> nums = {4,5,6,7,0,1,2};
    int target = 0;

    Solution obj;
    int ans = obj.search(nums, target);

    cout << ans;

    return 0;
}