#include<bits/stdc++.h>	//#include<iostream>
using namespace std;


class Solution {    // Find out how many times the array is rotated => (Right rotated array ; No duplicates)
public:

// OPTIMAL: t = log(n)
    int findKRotation(vector<int> &nums)  {
        int n = nums.size();
        int low = 0, high = n - 1;

        if(n == 1 || nums[0] <= nums[n-1]) return 0; // array already sorted

        while(low <= high){
            int mid = low + (high-low)/2;

            if(mid < n-1 && nums[mid] > nums[mid+1]){   // comparing from it's right..
                return (mid + 1);
            }else if(mid > 0 && nums[mid-1] > nums[mid]){   // comparing from it's left..
                return mid;
            }

            if(nums[low] <= nums[mid]){ // left is sorted => *U* you may find the Breaking point on right
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }

        return 0;
    }
};


// BRUTE: t = n
    // int findKRotation(vector<int> &nums)  {
    //     int n = nums.size();
    //     for(int i=0; i<n-1 ; i++){
    //         if(nums[i] > nums[i+1]) return (i + 1);
    //     }
    //     return 0;
    // }


int main(){
    vector<int> nums = {3,4,5,6,7,1,2};
    Solution obj;
    int ans = obj.findKRotation(nums);
    cout << ans << endl;
    return 0;
}