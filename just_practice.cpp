#include<bits/stdc++.h>	//#include<iostream>
using namespace std;

class Solution {
public:
    // my way... (optimal)   t=n
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int ans1 = -1, ans2 = -1;

        int low = 0, high = n-1;
        while(low <= high){
            int mid = (low + high)/2;

            // Lower Bound: starting idx..
            if(nums[mid] >= target){
                ans1 = mid;
                ans2 = mid;
                high = mid - 1;
            }
            else{
                // ans2 = mid;
                low = mid + 1;
            }
        }
        if(ans1 == n || nums[ans1] != target) return {-1,-1};

        low = 0, high = n-1;
        while(low <= high){
            int mid = (low + high)/2;

            if(nums[mid] <= target){
                ans2 = mid;
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }

        return {ans1, ans2};
    }
};

int main(){
    vector<int> nums = {1,3,3,3,4,5};
    int x = 3;

    Solution obj;
    vector<int> ans = obj.searchRange(nums, x);

    cout << ans[0] << "," << ans[1];

    return 0;
}