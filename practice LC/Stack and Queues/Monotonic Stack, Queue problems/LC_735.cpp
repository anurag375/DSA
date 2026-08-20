#include<bits/stdc++.h>
using namespace std;

class Solution {    // 735. Asteroid Collision
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
    // optimal ONLY (striver):    t = 2n = n       s = n
        stack<int> st;
        int n = asteroids.size();

        for(int i=0; i<n; i++){
            if(asteroids[i] > 0){
                st.push(asteroids[i]);
                continue;
            }
            // *U* asteroids[i] is a -ve below this point

            while(!st.empty() && st.top() > 0 && st.top() < abs(asteroids[i])){   // check explicitely, as top() can store both +ve and -ve
                st.pop();
            }
            if(!st.empty() && st.top() == abs(asteroids[i])){
                st.pop();
                continue;
            }
            if(st.empty() || st.top() < 0){   // if asteroids[i] is the most powerful OR top() is -ve   ==>   ONLY cases where -ve element can be pushed
                st.push(asteroids[i]);
            }

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
    // vector<int> asteroids  = {5,1,-5,10};  // output: [10]
    vector<int> asteroids  = {-2,-1,1,2};  // output: [-1,1,2]
    vector<int> result = s.asteroidCollision(asteroids);
    for(int i=0; i<result.size(); i++){
        cout << result[i] << " ";
    }
    return 0;
}





// ====================
    // optimal ONLY (my-way):    t = 2n = n       s = n
        // stack<int> st;
        // int n = nums.size();

        // int i = 0;
        // while(i<n){
        //     if(nums[i] > 0){
        //         st.push(nums[i]);
        //         i++;
        //         continue;
        //     }
        //     // nums[i] is -ve below this point

        //     while(!st.empty() && st.top() > 0 && st.top() < abs(nums[i])){   // check explicitely, as top() can store both +ve and -ve
        //         st.pop();
        //     }
        //     if(!st.empty() && st.top() == abs(nums[i])){
        //         st.pop();
        //         i++;
        //         continue;
        //     }
        //     if(st.empty() && st.top() < 0){   // nums[i] is the most powerful    ==> ONLY case where -ve element can be pushed
        //         st.push(nums[i]);
        //     }

        //     i++;
        // }

        // vector<int> ans;
        // while(!st.empty()){
        //     ans.push_back(st.top());
        //     st.pop();
        // }
        // reverse(ans.begin(), ans.end());
        // return ans;