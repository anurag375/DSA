#include<bits/stdc++.h>	//#include<iostream>
using namespace std;

class Solution {    // 3979. Maximum Valid Pair Sum
public:
    int maxValidPairSum(vector<int>& nums, int k) {
    // BETTER: gpt-way: (2-pointer)   t = n   s = 1
        int n = nums.size();
        int maxLeft = 0;
        int ans = 0;
        for(int right=k; right<n; right++){
            maxLeft = max(maxLeft, nums[right - k]);
            ans = max(ans, maxLeft + nums[right]);
        }
        
        return ans;
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,3,5,2,8};
    int k = 2;
    
    cout << s.maxValidPairSum(nums, k) << endl;
    return 0;
}

    // BRUTE: my-way ONLY:   t = n*n   s = 1   ==> NOT ACCEPTED
        // int n = nums.size();
        // int maxi = 0;
        // for(int i=0; i<n; i++){
        //     for(int j=i+k; j<n; j++){
        //         maxi = max(maxi, nums[i] + nums[j]);
        //     }
        // }
        
        // return maxi;