#include<bits/stdc++.h>
using namespace std;

class Solution {    // 26. Remove Duplicates from Sorted Array
public:
    int removeDuplicates(vector<int>& nums) {
    // retry:
        int n = nums.size();
        int cnt = 1;    // no. of uniques
        int i = 0;
        int j = 1;

        while(j < n){
            if(nums[i] != nums[j]){
                nums[++i] = nums[j];    // assign.. [or you can swap values as well]
                cnt++;
            }
            j++;
        }
        return cnt;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {1,1,2};
    cout << sol.removeDuplicates(nums) << endl; // output: 2    ==> nums = [1,2,_]
    return 0;
}


    // optimals:

    // 2. ==> 2-pointer
        // int n = nums.size();
        // int i=0, j=0;
        // while(j<n){
        //     if(nums[i] != nums[j]){
        //         nums[++i] = nums[j];
        //     }
        //     j++;
        // }
        // return i+1;

        
    // 1. ==> 2-pointer
        // int n = nums.size();
        // int k=0;
        // for(int i=1; i<n; i++){
        //     if(nums[k] != nums[i]){
        //         nums[++k] = nums[i];
        //     }
        // }
        // return k+1; // no. of uniques..
