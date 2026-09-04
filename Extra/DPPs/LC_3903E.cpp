#include<bits/stdc++.h>	//#include<iostream>
using namespace std;

class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
    // brute (my-way):  t = n*n     s = 1
        int maxi = INT_MIN;
        int mini = INT_MAX;
        for(int i=0; i<nums.size(); i++){
            maxi = *max_element(nums.begin(), nums.begin() + i + 1);
            mini = *min_element(nums.begin() + i, nums.end());

            if((maxi - mini) <= k) return i;
        }
        return -1;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {5,0,1,4,2};   // Output: 3
    int k = 3;
    cout << sol.firstStableIndex(nums, k) << endl;
    return 0;
}