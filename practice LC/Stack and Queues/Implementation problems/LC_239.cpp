#include<bits/stdc++.h>	
using namespace std;

class Solution {    // 239. Sliding Window Maximum
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    // optimal (striver + my-way):      t = 2n      s = n + (n-k) [for deque + for ans storing]
        int n = nums.size();
        deque<int> dq;  // ** store index, NOT value  [somehow similar to stack, that stores Previous Greater Element]
        vector<int> ans; 

        for(int i=0; i<n; i++){
            // 1> Remove smaller/equal elements (indices) from back [NO need in future]
            while(!dq.empty() && nums[dq.back()] <= nums[i])    // (value check)
                dq.pop_back();

            // 2> Add current index to the back
            dq.push_back(i);    // (index)
            
            // 3> Add to answer-vector once first window is complete (atleat window's width is k-1)
            if(i >= k-1)    // ***U*** say for k=3 (3 size window), the 1st window starts from (index) k-1 = 2 
                ans.push_back(nums[dq.front()]);  // (value)
            
            // 4> Remove index from the front that will expire in next iteration (when window slides to right)
            if(!dq.empty() && dq.front() == i+1-k)    // **U** (index check) can also be <=
                dq.pop_front();   
        }
        return ans;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {1,3,-1,-3,5,3,6,7};     // Output: [3,3,5,5,6,7]
    int k = 3;
    vector<int> ans = sol.maxSlidingWindow(nums, k);
    for(int num:ans)
        cout << num << " ";
    return 0;
}


    // optimal (striver): [Everything is same as the above optimal code; except the steps order]
    // 
    // 1> = 4> from above; and the condition here is <= (NOT ==) 
    // 2> = 1> from above
    // 3> = 2> from above
    // 4> = 3> from above


// ========================


    // brute: t = (n-k)*k    s = (n-k)      ==>     TLE..
        // int n = nums.size();
        // vector<int> ans; 

        // for(int i=0; i<=n-k; i++){  // *U* stop at the start index of the rightmost window
        //     int maxi = INT_MIN;     // reset for every window
        //     for(int j=i; j<i+k; j++){
        //         maxi = max(maxi, nums[j]);
        //     }
        //     ans.push_back(maxi);
        // }
        // return ans;