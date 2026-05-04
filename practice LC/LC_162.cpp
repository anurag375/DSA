#include<bits/stdc++.h>	//#include<iostream>
using namespace std;


class Solution {    // 162. Find Peak Element
public:
    int findPeakElement(vector<int>& nums) {    

    // my-way optimal: t = log(n)      ==>>  ** L.C. code is MORE reliable than this **

        int n = nums.size();
        int low = 1, high = n - 2;
        int mid;

        // handle edge cases separately (check single-element array ; check 1st index ; check last index)
        if(n == 1 || nums[0] > nums[1]) return 0;
        else if(nums[n-2] < nums[n-1]) return n-1;

        
        low = 1; high = n - 2;
        while(low <= high){
            mid = low + (high-low)/2;

            if(nums[mid-1] < nums[mid] && nums[mid] > nums[mid+1]) return mid;
            
            else if(nums[mid-1] > nums[mid]) high = mid - 1;
            else low = mid + 1;
        }

        return mid;
    }
};


int main(){
    vector<int> nums = {1, 3, 2, 4, 1};
    // int target = 0;

    Solution obj;
    int ans = obj.findPeakElement(nums);

    cout << ans;

    return 0;
}