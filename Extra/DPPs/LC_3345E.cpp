#include<bits/stdc++.h>	//#include<iostream>
using namespace std;

class Solution {
// good-way: (my-way only):  t = (K * D)       s = 1
// [K = no. of digits] ; [D = no. of no.s checked from 'n' until the answer]

    int productOfDigits(int n){     // O(K)
        int prod = 1;
        while(n > 0){
            int rem = n % 10;
            prod *= rem;
            n /= 10;
        }
        return prod;
    }

public:
    int smallestNumber(int n, int t) {
        int i = n;
        while(productOfDigits(i) % t != 0){ // if not divisible -> increase 'i'  ==>  O(D)
            i++;
        }

        return i;
    }
};

int main(){
    Solution sol;
    // int n = 10, t = 2;  // output: 10
    int n = 15, t = 3;  // output: 16
    cout << sol.smallestNumber(n, t) << endl;
    return 0;
}