#include<bits/stdc++.h>	//#include<iostream>
using namespace std;

class Solution {    // Next Greater Element
public:
    vector<int> nextLargerElement(vector<int> arr) {
    // optimal:     t = 2n      s = n [just to store the answer]
        int n = arr.size();
        vector<int> result(n);
        stack<int> st;  // Stack to keep track of visited elements (from right->left)
        
        for(int i=n-1; i>=0; i--){
            while(st.empty() == false && st.top() <= arr[i]){  // keep poping till ...
                st.pop();
            }

            if(st.empty() == false){    // if 'st' is not empty => means we found a greater element there
                result[i] = st.top();
            }
            else result[i] = -1;
            
            st.push(arr[i]);    // this always runs
        }
        return result;
    }
};


int main(){
    Solution sol;
    vector<int> arr = {4,5,2,10,8};  // output: [5,10,10,-1,-1]
    vector<int> ans = sol.nextLargerElement(arr);
    for(int num:ans) cout << num << " ";
    // cout << "works" << endl;
    return 0;
}


// brute:     t = n*n [nearly]     s = n [just to store the answer]
    // vector<int> nextLargerElement(vector<int> arr) {
    //     int n = arr.size();
    //     vector<int> result(n, -1);  // Initialize result vector with -1

    //     for(int i = 0; i < n; i++){
    //         for(int j = i+1; j < n; j++){
    //             if(arr[j] > arr[i]){
    //                 result[i] = arr[j];
    //                 break;  // Found the next greater element, break the inner loop
    //             }
    //         }
    //     }
    //     return result;
