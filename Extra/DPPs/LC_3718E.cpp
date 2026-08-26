#include<bits/stdc++.h>	//#include<iostream>
using namespace std;

class Solution {    // 3718. Smallest Missing Multiple of K
public:
    int missingMultiple(vector<int>& nums, int k) {
    // my-way:  t = n*n [for 'find' + loop]     s = 1
        int n = nums.size();
        int multiple = 1;

        while(find(nums.begin(), nums.end(), k * multiple) != nums.end()){     // **U** 'k' found
            multiple++;
        }
        return (k * multiple);  // *U*
    }
};

int main(){
    Solution sol;
    vector<int> nums = {8,2,3,4,6};     int k = 2;     // output: 10
    // vector<int> nums = {1,4,7,10,15};     int k = 5;     // output: 5
    cout << sol.missingMultiple(nums, k) << endl;
    return 0;
}