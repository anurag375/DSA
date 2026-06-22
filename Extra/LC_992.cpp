#include<bits/stdc++.h>	//#include<iostream>
using namespace std;

class Solution {    // 992. Subarrays with K Different Integers

// t = 2n + 2n = O(n) ==>  *U* both 'right' and 'left' traverse once in the array   
// s = n
    int slidingWindow(vector<int>& nums, int k){
        unordered_map<int,int> mp;
        int cnt = 0;
        int left = 0, right = 0;

        while(right < nums.size()){
            mp[nums[right]]++;

            while(mp.size() > k){ // *U* remove the leftmost elements from window & map..
                mp[nums[left]]--;
                if(mp[nums[left]] == 0) mp.erase(nums[left]);// removing out the map's key

                left++;
            }
            if(mp.size() <= k) cnt += (right - left + 1);// **U** not == (always count <=)

            right++;
        }
        return cnt;
    }

public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return slidingWindow(nums, k) - slidingWindow(nums, k-1);
    }
};



int main(){
    Solution sol;
    vector<int> nums = {1,2,1,2,3};
    int k = 2;
    cout << sol.subarraysWithKDistinct(nums, k) << endl;
    return 0;
}



// class Solution {
//     private: 
//     int atMost(vector<int>& nums, int k){
//         int n = nums.size();
//         int cnt = 0, unique = 0;
//         int l = 0, r = 0;
//         vector<int> freq(n+1, 0);

//         while(r < n){
//             freq[nums[r]]++;
//             if(freq[nums[r]] == 1)
//                 unique++;

//             while(unique > k){
//                 freq[nums[l]]--;
//                 if(freq[nums[l]] == 0)
//                     unique--;
//                 l++;
//             }

//             cnt += (r - l + 1);
//             r++;
//         }

//         return cnt;
//     }
// public:
//     int subarraysWithKDistinct(vector<int>& nums, int k) {
//         return atMost(nums, k) - atMost(nums, k-1);
//     }
// };
