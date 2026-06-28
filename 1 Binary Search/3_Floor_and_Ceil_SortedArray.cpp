#include<bits/stdc++.h>	//#include<iostream>
using namespace std;


class Solution {
public:
    vector<int> getFloorAndCeil(vector<int> nums, int x) {
        int n = nums.size();
        int ansF = -1, ansC = -1;   // *U* default answers
int idx;
        // finding ceil, (or 'low') : Lower Bound   ==> ***U*** only for ceil VALUE (NOT for INDEX)
        int low = 0, high = n - 1;
        while(low <= high){
            int mid = low + (high-low)/2;

            if(nums[mid] >= x){
                ansC = nums[mid];
                high = mid - 1;
idx=mid;
            }else{
                low = mid + 1;
            }
        }
cout<<"ceil: " <<idx<<"\n\n";
        // finding floor, (or 'high') : modified Lower Bound    ==> ***U*** ONLY for floor VALUE
        low = 0, high = n - 1;
        while(low <= high){
            int mid = low + (high-low)/2;

            if(nums[mid] <= x){
                ansF = nums[mid];
                low = mid + 1;
idx=mid;
            }else{
                high = mid - 1;
            }
        }
cout<<"floor: " <<idx<<"\n\n";
        return {ansF, ansC};
    }
};



int main(){
    vector<int> nums = {1,2,3,3,3,5,6,7,8};
    int x = 3;

    Solution obj;
    vector<int> ans = obj.getFloorAndCeil(nums, x);

    cout << ans[0] << "," << ans[1];

    return 0;
}