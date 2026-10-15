#include<bits/stdc++.h>	//#include<iostream>
using namespace std;

class Solution {    // 268. Missing Number
public:
    int missingNumber(vector<int>& nums) {
    // optimals: 
    // 1. ==> arithmatic 
        int n = nums.size();
        long long nsum = n * (n+1)/2;
        long long sum = 0;
        for(auto it:nums){
            sum += it;
        }

        return (int)nsum - (int)sum;

    // 2. ==> XOR way..
        // int n = nums.size();
        // int arrSum = 0;
        // int xorSum = 0;
        
        
        // for(int i=1; i<=n; i++){
        //     arrSum ^= nums[i-1];    // *U* don't use "+" here
        //     xorSum ^= i;
        // }
        // return (xorSum ^ arrSum);
    }
};

int main(){
    Solution sol;
    vector<int> nums = {3,0,1};     // output: 2
    cout << sol.missingNumber(nums) << endl;
    return 0;
}