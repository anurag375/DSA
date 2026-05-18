#include<bits/stdc++.h>	//#include<iostream>
using namespace std;

#include <algorithm>
class Solution {

// optimal:     t = log(high - low + 1) * n
    bool check(vector<int> &nums, int m, int curr_page_limit){  // curr_page_limit = i = mid
        int cnt_students = 1;   // *U* starts from 1
        int pages_sum = 0; 

        for(int ele:nums){
            if(pages_sum + ele > curr_page_limit){
                cnt_students ++;
                pages_sum = 0;
            }
            pages_sum += ele;
        }

        return (cnt_students <= m);     // ******U****** not ==, because if we can distribute pages to students fewer than 'm', we can also distribute to 'm' students
    }

    int sumOfArray(vector<int> &nums){
        int sum = 0;
        for(int ele:nums) sum += ele;
        return sum;
    }

public:
    int findPages(vector<int> &nums, int m)  {
        int n = nums.size();
        int low = *max_element(nums.begin(), nums.end());
        int high = sumOfArray(nums);
        int ans = 0;

        while(low <= high){
            int mid = low + (high-low)/2;

            if(check(nums, m, mid) == true){
                ans = mid;
                high = mid - 1; // move left ==> because right jaoge toh no. of pages aur jyada hoo jayega (jabki hame usko kam krna h) ==> moving LEFT means decreasing allowed maximum pages/workload
            }else{
                low = mid + 1;
            }
        }
        return ans; // *U* or low;
    }
    
};

int main(){
    Solution obj;
    vector<int> nums = {12, 34, 67, 90};
    int m = 2;

    int result = obj.findPages(nums, m);
    cout << result << endl;
    
    return 0;
}


// BRUTE:     t = (high - low + 1) * n  
    // int findPages(vector<int> &nums, int m)  {
    //     int n = nums.size();

    //     if(n < m) return -1;    // no possible case

    //     int low = *max_element(nums.begin(), nums.end());
    //     int high = sumOfArray(nums);

    //     for(int i=low; i<=high; i++){
    //         if(check(nums, m, i)) return i;
    //     }

    //     return -1;  // Suppose somehow no value satisfies the condition inside the for loop, then we return -1. 
    // }