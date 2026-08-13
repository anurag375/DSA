#include<bits/stdc++.h>	//#include<iostream>
using namespace std;

class Solution {    // Previous smaller element     ==>    [diff. from striver sheet]

public:
    vector<int> nextGreaterElement(vector<int>& nums) {
    // optimal:   t = O(n + n)  [for traversal + for st.pop]   s = O(n + n)  [for stack + for storing ans]
        int n = nums.size();
        stack<int> st;
        vector<int> ans(n, -1);

        for(int i=0; i<=n; i++){
            while(!st.empty() && st.top() >= nums[i]){
                st.pop();
            }
            
            if(!st.empty()) ans[i] = st.top();
            // ans[i] = (st.empty()) ? -1 : st.top();   // striver-way

            st.push(nums[i]);   // *U* imp. step
        }
        return ans;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {1,3,4,2};  // output: [-1,1,3,1]

    vector<int> ans = sol.nextGreaterElement(nums);
    for(int num:ans) cout << num << " ";
    return 0;
}


    // brute:   t = n*n     s = n   [only to store]
        // int n = nums.size();
        // vector<int> ans(n, -1);
        // for(int i=0; i<=n; i++){
        //     for(int j=i-1; j>=0; j--){
        //         if(nums[j] < nums[i]){
        //             ans[i] = nums[j];
        //             break;
        //         }
        //     }
        // }
        // return ans;