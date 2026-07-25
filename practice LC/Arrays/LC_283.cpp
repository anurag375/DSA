#include<bits/stdc++.h>	//#include<iostream>
using namespace std;

class Solution {    // 283. Move Zeroes
public:
    void moveZeroes(vector<int>& nums) {
    // optimal (my way):    t = n   s = 1
        int n = nums.size();
        int i = 0;
        int j;  // it catches the non-zeros and send to front 

        // 1> place 'i' at the 1st zero (the first position that needs to be filled)
        while(i < n && nums[i] != 0) i++;

        // 2> traverse the remaining array; whenever a non-zero is found, swap with 1st 0
        j = i + 1;
        while(j < n){
            if(nums[j] != 0){
                swap(nums[i], nums[j]);
                i++;
            }
            j++;
        }
        // NO return (void function)
    }
};

int main(){
    Solution sol;
    vector<int> nums = {0,1,0,3,12};
    sol.moveZeroes(nums);   // modifies nums directly
    for(int x : nums)
        cout << x << " ";
    return 0;
}