#include<bits/stdc++.h>	//#include<iostream>
using namespace std;

class Solution {    // 907. Sum of Subarray Minimums
public:
// optimal:     t = 2n+2n+n = 5n      s = 5n [similar to its time compl.]
    vector<int> previousSmallerEqualElement(vector<int>& arr){
        int n = arr.size();
        stack<int> st;
        vector<int> psee(n);

        for(int i=0; i<n; i++){
            while(!st.empty() && arr[st.top()] >= arr[i])
                st.pop();
            if(!st.empty()) psee[i] = st.top();     // *U* stores index, not value
            else psee[i] = -1;  // *U* put out of range index, So '-1'
            st.push(i);     // *U* stores index, not value
        }
        return psee;
    }

    vector<int> nextSmallerElement(vector<int>& arr){
        int n = arr.size();
        stack<int> st;
        vector<int> nse(n);

        for(int i=n-1; i>=0; i--){
            while(!st.empty() && arr[st.top()] > arr[i])    // ***U*** NO '='
                st.pop();
            if(!st.empty()) nse[i] = st.top();    // *U* stores index, not value
            else nse[i] = n;    // *U* put out of range index, So 'n'
            st.push(i);     // *U* stores index, not value
        }
        return nse;
    }


    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        int sum = 0;
        int mod = int(1e9 + 7);

        vector<int> psee = previousSmallerEqualElement(arr);
        vector<int> nse = nextSmallerElement(arr);

        for(int i=0; i<n; i++){
            int leftSmaller = i - psee[i];
            int rightSmaller = nse[i] - i;
            // mini = min(arr[j], mini);
            sum = (sum + (rightSmaller * leftSmaller * 1LL * arr[i]) % mod) % mod;
        
        }
        return sum;
    }
};


int main(){
    Solution sol;
    vector<int> arr = {3,1,2,4};    // output: 17
    // vector<int> arr = {11,81,94,43,3};    // output: 444
    cout << sol.sumSubarrayMins(arr) << endl;
    
    return 0;
}


    // brute:   t = n*n     s = 1       ==> gives TLE
        // int n = arr.size();
        // int sum = 0;
        // int mod = int(1e9 + 7);

        // for(int i=0; i<n; i++){
        //     int mini = arr[i];
        //     for(int j=i; j<n; j++){
        //         mini = min(arr[j], mini);
        //         sum = (sum + mini) % mod;
        //     }
        // }
        // return sum;