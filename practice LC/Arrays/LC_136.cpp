#include<bits/stdc++.h>	//#include<iostream>
using namespace std;

class Solution {    // 136. Single Number
public:
    int singleNumber(vector<int>& nums) {
    // optimal:     t = n   s = 1
    // [Each XOR operation (^) takes O(1) time]
        int xorr=0;
        for(auto it:nums){
            xorr ^= it;
        }

        return xorr;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {2,2,1,4,1};
    cout << sol.singleNumber(nums) << endl;
    return 0;
}