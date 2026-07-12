#include<bits/stdc++.h>	//#include<iostream>
using namespace std;

class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
    // my-way ONLY:   t = n    s = 1
        int n = nums.size();
        if(n == 1) return true;  // *U* Edge case: single element array
        int mid = nums[n/2];

        int cnt = 0;
        for(int num:nums){
            if(num == mid) cnt++;
        }

        if(cnt == 1) return true;
        return false;
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,2,3};
    // vector<int> nums = {1,2,2};
    cout << s.isMiddleElementUnique(nums) << endl;
    return 0;
}