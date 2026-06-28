#include<bits/stdc++.h>	//#include<iostream>
using namespace std;


class Solution {
public:
    int countOccurrences(vector<int>& arr, int target) {
        // Your code goes here
        int n = arr.size();
        int floor_idx = -1, ceil_idx = -1;

        // find ceil idx (modified Lower Bound), ==> ***U*** ONLY for ceil INDEX (NOT for VALUE)
        int low = 0, high = n-1;
        while(low <= high){
            int mid = low + (high-low)/2;

            if(arr[mid] <= target){
                ceil_idx = mid;
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }

        // NOT found:  
        if(ceil_idx == -1 || arr[ceil_idx] != target) return 0; 
        // *U* 1st cond. is for: [for target smaller than every element] & [empty array]  
        // (specially for cases like, arr = [5,7,7,8,8,10]  target = 6)
        
        // find floor idx (Lower Bound), ==> ***U*** ONLY for floor INDEX (NOT for VALUE)
        low = 0, high = n-1;
        while(low <= high){
            int mid = low + (high-low)/2;

            if(arr[mid] >= target){
                floor_idx = mid;
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }

cout << floor_idx << " , " << ceil_idx << endl;

        return (ceil_idx - floor_idx + 1);
    }
};


int main(){
    vector<int> nums = {1,2,4,4,4,4,4,5,6,7,8};
    int x = 4;
    
    Solution obj;
    int count = obj.countOccurrences(nums, x);
    cout << count << endl;
    
    return 0;
}