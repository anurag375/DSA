#include<bits/stdc++.h>
using namespace std;

class Solution {    // 735. Asteroid Collision
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;

        // for(int i=0; i<nums.size(); i++){
        int i = 0;
        while(i<nums.size()){
            if(nums[i] > 0){
                st.push(nums[i]);
                i++;
                continue;
            }

            while(!st.empty() && st.top() < abs(nums[i]))    // nums[i] is -ve
                st.pop();
            if(!st.empty() && st.top() == abs(nums[i])){
                st.pop();
                i++;
                continue;
            }
            if(st.empty())   // nums[i] is -ve && it is not the most powerful
                st.push(nums[i]);

            i++;
        }

        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main(){
    Solution s;
    vector<int> asteroids  = {5,1,-5,10};  // output: []
    vector<int> result = s.nextGreaterElements(asteroids);
    for(int i=0; i<result.size(); i++){
        cout << result[i] << " ";
    }
    return 0;
}





// ====================
    // vector<int> nextGreaterElements(vector<int>& nums) {
    //     stack<int> st;

    //     // for(int i=0; i<nums.size(); i++){
    //     int i = 0;
    //     while(i<nums.size()){
    //         while(!st.empty() && st.top() > 0 && nums[i] < 0 && st.top() < abs(nums[i]))    // nums[i] is -ve
    //             st.pop();
    //         if(nums[i] < 0 && st.empty())   // nums[i] is -ve && it is not the most powerful
    //             continue;
    //         // if(st.empty() && nums[i] < 0)
    //             // st.push(nums[i]);
    //         st.push(nums[i]);

    //         i++;
    //     }

    //     vector<int> ans;
    //     while(!st.empty()){
    //         ans.push_back(st.top());
    //         st.pop();
    //     }
    //     reverse(ans.begin(), ans.end());
    //     return ans;
    // }