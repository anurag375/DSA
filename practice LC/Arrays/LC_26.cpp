#include<bits/stdc++.h>	//#include<iostream>
using namespace std;

class Solution {    // 26. Remove Duplicates from Sorted Array 
    // NOTE: given that the array is already SORTED -> in non-decreasing order... 
    // ⭐ 2 TASKS we MUST do: 1> shift all unique elements to left     2> return count of unique elements
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        // optimals: (2-pointer):    t = n   s = 1
        
        // 1.
        // int k=0;
        // for(int i=1; i<n; i++){
        //     if(nums[k] != nums[i]){
        //         nums[++k] = nums[i];
        //     }
        // }
        // return k+1; // no. of uniques..


        // 2. cleaner way
        int i=0, j=0;
        while(j<n){
            if(nums[i] != nums[j]){
                nums[++i] = nums[j];
            }
            j++;
        }
        return i+1;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {2,3,3,5,8,8,8};
    cout << "unique elements : " << sol.removeDuplicates(nums) << endl;
    return 0;
}

    // brute: (using set):   t = (n log n + unique ele.)     s = n
    // insert all elements from the array into the set -> then count all elements in the set
