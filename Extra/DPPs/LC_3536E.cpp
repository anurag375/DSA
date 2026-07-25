#include<bits/stdc++.h>	//#include<iostream>
using namespace std;

class Solution {    // 3536. Maximum Product of Two Digits
public:
    int maxProduct(int n) {
    // gpt + my-way:    t = O(log₁₀ n)    s = 1
        int largest = -1;
        int secLargest = -1;

        int temp = n;
        while(temp > 0){
            int rem = temp % 10;

            if(largest <= rem){     // **U** add '<=' instead of '<' ==> updates 'secLargest' when the largest digit appears more than once
                secLargest = largest;
                largest = rem;
            }else if(secLargest < rem){
                secLargest = rem;
            }

            temp = temp / 10;
        }

        return largest * secLargest;    // *U* return 2 digits (even if any one is = 0)
    }
};

int main(){
    Solution sol;
    int n = 22;
    // int n = 124;
    cout << sol.maxProduct(n) << endl;
    return 0;
}