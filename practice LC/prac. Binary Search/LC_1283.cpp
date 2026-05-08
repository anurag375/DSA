#include<bits/stdc++.h>	//#include<iostream>
using namespace std;


class Solution {    // 1283. Find the Smallest Divisor Given a Threshold
    // optimal: t = log(maxElement) * n
    int calcSUM(vector<int>& nums, int threshold, int i){
        int sum = 0;
        for(int ele:nums){
            sum += (ele + i - 1)/i;     // *U* ceil division
        }

        return sum;
    }

public:

    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());
        int ans = -1;
        
        while(low <= high){
            int mid = low + (high-low)/2;

            int sum = calcSUM(nums, threshold, mid);
            if(sum <= threshold){
                ans = mid;
                high = mid - 1;     // trying to find 'smallest' divisor
            }else{
                low = mid + 1;
            }
        }

        return ans;  
    } 


};


int main(){
    Solution obj;
    vector<int> nums = {1,2,5,9};
    int threshold = 6;

    int ans = obj.smallestDivisor(nums, threshold);
    cout << ans << endl;
    
    return 0;
}


// BRUTE (ONLY this func. is different): t = maxElement * n        ==> **U**
// public:
    // int smallestDivisor(vector<int>& nums, int threshold) {
    //     int low = 1;
    //     int high = *max_element(nums.begin(), nums.end());
        
    //     for(int i=low; i<=high; i++){    // divisors..
    //         int sum = calcSUM(nums, threshold, i);
    //         if(sum <= threshold) return i;  // 'smallest' divisor
    //     }

    //     return -1;  // it won't run..
    // }
