#include<bits/stdc++.h>	//#include<iostream>
using namespace std;


class Solution {
public:
    vector<int> getFloorAndCeil(vector<int> nums, int x) {
        int n = nums.size();
        int ansF = -1, ansC = -1;   // *U* default answers

        // finding ceil, (or 'low') : modified Lower Bound
        int low = 0, high = n - 1;
        while(low <= high){
            int mid = low + (high-low)/2;

            if(nums[mid] >= x){
                ansC = nums[mid];
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }

        // finding floor, (or 'high') : Lower Bound
        low = 0, high = n - 1;
        while(low <= high){
            int mid = low + (high-low)/2;

            if(nums[mid] <= x){
                ansF = nums[mid];
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
        return {ansF, ansC};
    }
};



int main(){
    vector<int> nums = {1,2,4,4,5,6,7,8};
    int x = 3;

    Solution obj;
    vector<int> ans = obj.getFloorAndCeil(nums, x);

    cout << ans[0] << "," << ans[1];

    return 0;
}