#include<bits/stdc++.h>	//#include<iostream>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {

    // optimal: [Monotonic Stack]
    // t = (2n + 2n) = 4n [for travel + for st.pop]   s = 2n + n [for stack + for storing ans]
        int n = nums.size();
        vector<int> ans(n, -1);  // my-way..
        // vector<int> ans(n); // striver..
        stack<int> st;

        int ans_idx = n;
        for(int i=2*n-1; i>=0; i--){
            int idx = i % n;

            while(!st.empty() && st.top() <= nums[idx])   // 1. common task
                st.pop();

            if(i < n && !st.empty()) ans[idx] = st.top(); // *U* (i<n) needed ==> diff. task   // my-way..
            // if(i < n) ans[idx] = st.empty() ? -1 : st.top();    // striver

            st.push(nums[idx]);   // 2. common task
        }

        return ans;
    }
};

int main(){
    Solution s;
    // vector<int> nums = {1, 2, 1};   // output: [2,-1,2]
    vector<int> nums = {1,2,3,4,3};  // output: [2,3,4,-1,4]
    vector<int> result = s.nextGreaterElements(nums);
    for(int i=0; i<result.size(); i++){
        cout << result[i] << " ";
    }
    return 0;
}


    // brute (striver): [Double the given array hypothetically]:    t = n*n   s = n  [for storing]
        // int n = nums.size();
        // vector<int> ans(n, -1);

        // for(int i=0; i<n; i++){
        //     for(int j=i+1; j<=(i + n-1); j++){  // **U** traverse till it reaches 1 index previous of the same element (where it started) 
        //         int idx = j % n;    // traverse in loop
        //         if(nums[idx] > nums[i]){
        //             ans[i] = nums[idx];
        //             break;
        //         }
        //     }
        // }
        // return ans;



    // brute (my-way):  t = n*n     s = n  [for storing]
        // int n = nums.size();
        // vector<int> ans(n, -1);

        // for(int i=0; i<n; i++){
        //     bool found = false;
        //     for(int j=i+1; j<n; j++){
        //         if(nums[j] > nums[i]){
        //             found = true;
        //             // ans.push_back(nums[j]);
        //             ans[i] = nums[j];
        //             break;
        //         }
        //     }

        //     if(!found){
        //         for(int j=0; j<i; j++){
        //             if(nums[j] > nums[i]){
        //                 // ans.push_back(nums[j]); 
        //                 ans[i] = nums[j];
        //                 break;
        //             }
        //         }
        //     }
        // }
        // return ans;
