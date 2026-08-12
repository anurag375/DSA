#include<bits/stdc++.h>	//#include<iostream>
using namespace std;

class Solution {    // 907. Sum of Subarray Minimums
public:
    int sumSubarrayMins(vector<int>& arr) {
    // brute:   t = n*n     s = 1       ==> gives TLE
        int n = arr.size();
        int sum = 0;
        int mod = int(1e9 + 7);

        for(int i=0; i<n; i++){
            int mini = arr[i];
            for(int j=i; j<n; j++){
                mini = min(arr[j], mini);
                sum = (sum + mini) % mod;
            }
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