#include<bits/stdc++.h>	//#include<iostream>
using namespace std;

class Solution {    // 4097. Minimum Value of Merged Integers
public:
    int minMergedInteger(vector<int>& nums) {
    // Contest:
        int n = nums.size();
        int minMerg = INT_MAX;

        for(int i=0; i <= n-2; i+=2){
            int merg = stoi( to_string(nums[i]) + to_string(nums[i+1]) );
            minMerg = min(minMerg, merg);
        }

        return minMerg;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {23,55,42,21};   // Output: 2355
    cout << sol.minMergedInteger(nums) << endl;
    return 0;
}