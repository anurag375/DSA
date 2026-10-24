#include<bits/stdc++.h>
using namespace std;

class Solution {    // 4089. Count Subarrays With Loose Bounds
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
    // (my-way) contest:   [based on Moore's voting algo.]
        int n = nums.size();
        long long ans = 0;

        int i = 0;
        long long fullSubArrLen = 0;
        while(i < n){
            if((nums[i] < minK || nums[i] > maxK) && fullSubArrLen != 0){   // reset..    **U** "fullSubArrLen"
                long long subarrays = fullSubArrLen * (fullSubArrLen + 1) / 2;
                ans += subarrays;
                fullSubArrLen = 0;
                
            }else if(nums[i] >= minK && nums[i] <= maxK){
                fullSubArrLen++;
            }

            i++;
        }

        if(fullSubArrLen != 0){   // last time calc. at the end
            long long subarrays = fullSubArrLen * (fullSubArrLen + 1) / 2;
            ans += subarrays;
        }

        return ans;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {1,4,7,3};   // output: 4
    int minK = 1;
    int maxK = 5;
    cout << sol.countSubarrays(nums, minK, maxK) << endl;
    return 0;
}