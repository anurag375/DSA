#include<bits/stdc++.h>	//#include<iostream>
using namespace std;

class Solution {    // 1464. Maximum Product of Two Elements in an Array
public:
    int maxProduct(vector<int>& nums) {
    // optimal (my-way): (traverse, find and return)    t = n   s = 1
        int largest = INT_MIN;
        int secLargest = INT_MIN;

        for(int num:nums){
            if(largest <= num){     // **U** write "<=", not "<" [ONLY for this question]
                secLargest = largest;
                largest = num;
            }
            else if(secLargest < num){
                secLargest = num;
            }
        }

        return (largest - 1)*(secLargest - 1);
    }
};

int main(){
    Solution sol;
    vector<int> nums = {1,5,4,5};   // take 2 max. no.s (5 and 5) => (5-1)*(5-1) => 4*4 => 16 [output]
    cout << sol.maxProduct(nums) << endl;
    return 0;
}

// brute (gpt-way): (sort, find and return)    t = n * n log(n)   s = 1
