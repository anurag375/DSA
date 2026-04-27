#include<bits/stdc++.h>	//#include<iostream>
using namespace std;

class Solution {
public:

    vector<int> getFloorAndCeil_idx(vector<int>& nums, int target) {
        int n = nums.size();
        int floor_idx = -1, ceil_idx = -1;

        int low = 0, high = n-1;
        while(low <= high){
            int mid = (low + high)/2;

            // modified Lower Bound
            if(nums[mid] <= target){
                floor_idx = mid;
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }

        // Lower Bound method: ceil_idx value..
        low = 0, high = n-1;
        while(low <= high){
            int mid = (low + high)/2;

            if(nums[mid] >= target){
                ceil_idx = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        
        return {floor_idx, ceil_idx};
    }
};

int main(){
    vector<int> nums = {1,2,3,3,4,4,5,6,7,8};
    int x = 2;

    Solution obj;
    vector<int> ans = obj.getFloorAndCeil_idx(nums, x);

    cout << ans[0] << "," << ans[1];

    return 0;
}