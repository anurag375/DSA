#include<bits/stdc++.h>	//#include<iostream>
using namespace std;

class Solution {    // 3658. GCD of Odd and Even Sums

// my-way:
    int findGCD(int a, int b){  // 'b' is larger (so, iterate in smaller one)
        int gcd = 0;
        for(int i=1; i<=a; i++){
            if(a%i == 0 && b%i == 0) gcd = i;
        }
        return gcd;
    }

public:
    int gcdOfOddEvenSums(int n) {
        int sumOdd = 0;
        int sumEven = 0;

        for(int i=1; i<=n; i++){
            sumOdd += (2*i - 1);
            sumEven += (2*i);
        }

        return findGCD(sumOdd, sumEven);    // *U* Notice: sumEven is always larger
    }
};

int main(){
    Solution sol;
    int n = 4;
    cout << sol.gcdOfOddEvenSums(n) << endl;  // Example usage
    return 0;
}