#include<bits/stdc++.h>
using namespace std;

class Solution {    // 4088. Difference Between Peaks and Valleys
public:
    int peakValleyDifference(vector<int>& nums) {
    // optimal: contest:    t = n    s = 1
        int n = nums.size();
        int peaks = 0;
        int valleys = 0;

        for(int i=1; i<n-1; i++){
            if(nums[i] > nums[i - 1] && nums[i] > nums[i + 1])
                peaks += nums[i];
            if(nums[i] < nums[i - 1] && nums[i] < nums[i + 1])
                valleys += nums[i];
        }

        return peaks - valleys;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {1,5,2,4,1,3,0};    // output: 9
    cout << sol.peakValleyDifference(nums) << endl;
    return 0;
}