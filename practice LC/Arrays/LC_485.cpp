#include<bits/stdc++.h>	//#include<iostream>
using namespace std;

class Solution {    // 485. Max Consecutive Ones
public:
    int findMaxConsecutiveOnes(vector<int>& nums) { 
        // optimal (my way):    t = n   s = 1
        int cnt = 0;
        int maxCnt = 0;
        for(int num:nums){
            if(num == 1){
                cnt++;
                maxCnt = max(cnt, maxCnt);
            }else{
                cnt = 0;
            }
            // max_cnt = max(max_cnt, cnt);     // writing here will also work
        }
        return maxCnt;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {1,1,0,1,1,1};
    cout << sol.findMaxConsecutiveOnes(nums) << endl;
    return 0;
}