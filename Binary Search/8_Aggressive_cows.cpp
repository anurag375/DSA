#include<bits/stdc++.h>
using namespace std;

class Solution {
// optimal:     t = n log n + log(max-min) * n   --> (n = length of array)

    bool canBePlaced(vector<int> &nums, int k, int distance){  // distance = i
        int cows_placed = 1;    // initially 1 cow is already placed (at index 0)
        int last_pos = nums[0];      // for tracking position/index value

        for(int j=1; j<nums.size(); j++){
            if(nums[j] - last_pos >= distance){
                cows_placed ++;
                last_pos = nums[j];
            }
            if(cows_placed == k) return true;
        }
        return false;
    }

public:
    int aggressiveCows(vector<int> &nums, int k) {

        sort(nums.begin(), nums.end());
        int min = nums[0];
        int max = nums[nums.size() - 1];

        int low = 1;
        int high = max - min;

        while(low <= high){
            int mid = low + (high-low)/2;

            if(canBePlaced(nums, k, mid) == true){
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }

        return high;    // *U*
    }
};

int main(){
    Solution obj;
    vector<int> nums = {0, 3, 4, 7, 10, 9};
    int k = 4;

    int result = obj.aggressiveCows(nums, k);
    cout << result << endl;
    
    return 0;
}


// BRUTE: (ONLY this part is diff.) t = n log n + (max-min) * n   --> (n = length of array)
// public:
//     int aggressiveCows(vector<int> &nums, int k) {

//         sort(nums.begin(), nums.end()); // **U** imp. first step
//         int min = nums[0];
//         int max = nums[nums.size() - 1];

//         for(int i=1; i<=(max-min); i++){
//             if(canBePlaced(nums, k, i) == true) continue;
//             else return i-1;    // *U*
//         }
//         return max-min;     // ***U*** runs when 'else' is never executed inside the loop
//     }