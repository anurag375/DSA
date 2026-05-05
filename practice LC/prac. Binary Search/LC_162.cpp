#include<bits/stdc++.h>	//#include<iostream>
using namespace std;


class Solution {    // 162. Find Peak Element
public:
    int findPeakElement_OPTIMAL(vector<int>& nums) {    

    // my-way optimal: t = log(n)      ==>>  ** this is EASIER; BUT L.C. code is MORE Elegant for interviews **

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



    int findPeakElement_BRUTE(vector<int>& nums) {    // t = n ==> ** EASIER than L.C code
        int n = nums.size();

        // handle edge cases separately (check single-element array ; check 1st index ; check last index)
        if(n == 1 || nums[0] > nums[1]) return 0;
        else if(nums[n-2] < nums[n-1]) return n-1;

        for(int i=1; i<n-1; i++){
            if(nums[i-1] < nums[i] && nums[i] > nums[i+1]) return i;
        }

        return -1; // safety (never actually used)
    }



};


int main(){
    vector<int> nums = {1, 3, 2, 4, 1};

    Solution obj;
    int ans = obj.findPeakElement_OPTIMAL(nums);
    // int ans = obj.findPeakElement_BRUTE(nums);

    cout << ans;

    return 0;
}