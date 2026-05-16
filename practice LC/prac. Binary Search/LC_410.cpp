#include<bits/stdc++.h>	//#include<iostream>
using namespace std;

class Solution {

// optimal:     t = log(high - low + 1) * n
    bool check(vector<int> &nums, int k, int allowed_sum){  // allowed_sum = i = mid
        int sum = 0;
        int cnt_k = 1;  // starts from 1

        for(int ele:nums){
            if(sum + ele > allowed_sum){
                cnt_k ++;
                sum = 0;
            }
            sum += ele;
        }
        return (cnt_k <= k);
    }

    int sumOfArray(vector<int> &nums){
        int sum = 0;
        for(int ele:nums) sum += ele;
        return sum;
    }

public:
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        int high = sumOfArray(nums);
        int ans = 0;

        while(low <= high){
            int mid = low + (high-low)/2;

            if(check(nums, k, mid) == true){
                ans = mid;
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }

        return ans;     // *U* or low;
    }
};


int main(){
    Solution obj;
    vector<int> nums = {7,2,5,10,8};
    int k = 2;
    
    int result = obj.splitArray(nums, k);
    cout << result << endl;
    
    return 0;
}


// BRUTE:  t = (high - low + 1) * n
// public:
//     int splitArray(vector<int>& nums, int k) {
//         int low = *max_element(nums.begin(), nums.end());
//         int high = sumOfArray(nums);

//         for(int i=low; i<=high; i++){
//             if(check(nums, k, i) == true) return i;
//         }
//     }