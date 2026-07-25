#include<bits/stdc++.h>	//#include<iostream>
using namespace std;

class Solution {    // 189. Rotate Array
public:
    void rotate(vector<int>& nums, int k) {
    // optimal (striver way):    t = n   s = 1
        int n = nums.size();
        k = k % n; // *U* for every multiple of 'n', k-rotate becomes 0-rotate

       reverse(nums.begin(), (nums.begin() + n-k));  // *U*
       reverse((nums.begin() + n-k), nums.end());    // *U*

       reverse(nums.begin(), nums.end());

    }
};



int main(){
    Solution sol;
    vector<int> nums = {1,2,3,4,5,6,7}; // output: [5,6,7,1,2,3,4]
    int k = 3;

    sol.rotate(nums, k);   // modifies nums directly
    for(int x : nums)
        cout << x << " ";
    return 0;
}


    // better (striver way): (temporary array)    t = n     s = k  [k = size of temporary array]
        // int n = nums.size();
        // vector<int> tempArr;

        // k %= n; // *U* Must do

        // // 1> store the back portion in a temporary array 'tempArr'
        // for(int i=n-k; i<n; i++){
        //     tempArr.push_back(nums[i]);
        // }

        // // 2> Right-shift the front portion by 'k' places: 
        // // **U** (can be done ONLY in reverse order: otherwise overwrite happens)
        // for(int i=n-k-1; i>=0; i--){
        //     nums[i+k] = nums[i];
        // }

        // // 3> copy-back the tempArr elements to the front portion of 'nums'
        // for(int i=0; i<k; i++){
        //     nums[i] = tempArr[i];
        // }