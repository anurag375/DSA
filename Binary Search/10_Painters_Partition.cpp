
// =============================================================================
// =============================================================================
// TYPE 1:  TUF: more difficult
// optimal:     t = log(high - low + 1) * n


#include<bits/stdc++.h>	//#include<iostream>
using namespace std;

class Solution {

    bool check(vector<int> &nums, int painters, long long board_unit_limit){  // board_unit_limit = i = mid
        int cnt_painters = 1;   // *U* starts from 1
        long long units_sum = 0; 

        for(int ele:nums){
            if(units_sum + ele > board_unit_limit){
                cnt_painters ++;
                units_sum = 0;
            }
            units_sum += ele;
        }

        return (cnt_painters <= painters);     // ******U****** not ==, because if we can distribute pages to students fewer than 'm', we can also distribute to 'm' students
    }

    long long sumOfArray(vector<int> &nums){
        long long sum = 0;
        for(int ele:nums) sum += ele;
        return sum;
    }

public:
    int paint(int painters, int B, vector<int>& nums)  {
        int n = nums.size();
        long long low = *max_element(nums.begin(), nums.end());
        long long high = sumOfArray(nums);
        long long ans = 0;

        while(low <= high){
            long long mid = low + (high-low)/2;

            if(check(nums, painters, mid) == true){
                ans = mid;
                high = mid - 1; // move left ==> because moving LEFT means decreasing allowed maximum pages/workload
            }else{
                low = mid + 1;
            }
        }
        return (1LL * ans * B) % 10000003; // ****U**** Because after modulo: the result is always: 0 to 10000002 ; which safely fits inside int.
    }
    
};

int main(){
    Solution obj;
    vector<int> nums = {1, 10};
    int painters = 2, B = 5;

    int result = obj.paint(painters, B, nums);
    cout << result << endl;
    return 0;
}

// painters = A
// boards = C



// =============================================================================
// =============================================================================
// TYPE 2: GFG: optimal only (brute DIY):     t = log(high - low + 1) * n


// https://www.geeksforgeeks.org/problems/the-painters-partition-problem1535/1

// class Solution {

// // optimal:     t = log(high - low + 1) * n
//     bool check(vector<int> &arr, int k, int board_unit_limit){  
//         int cnt_painters = 1;   // *U* starts from 1
//         int units_sum = 0; 

//         for(int ele:arr){
//             if(units_sum + ele > board_unit_limit){
//                 cnt_painters ++;
//                 units_sum = 0;
//             }
//             units_sum += ele;
//         }

//         return (cnt_painters <= k); 
//     }

//     int sumOfArray(vector<int> &arr){
//         int sum = 0;
//         for(int ele:arr) sum += ele;
//         return sum;
//     }

// public:
//     int minTime(vector<int> &arr, int k)  {
//         int n = arr.size();
//         int low = *max_element(arr.begin(), arr.end());
//         int high = sumOfArray(arr);
//         int ans = 0;

//         while(low <= high){
//             int mid = low + (high-low)/2;

//             if(check(arr, k, mid) == true){
//                 ans = mid;
//                 high = mid - 1; // move left ==> because right jaoge toh no. of pages aur jyada hoo jayega (jabki hame usko kam krna h) ==> moving LEFT means decreasing allowed maximum pages/workload
//             }else{
//                 low = mid + 1;
//             }
//         }
//         return ans; // *U* or low;
//     }
    
// };