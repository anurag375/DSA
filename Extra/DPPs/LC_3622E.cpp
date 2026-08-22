#include<bits/stdc++.h>	//#include<iostream>
using namespace std;

class Solution {    // 3622. Check Divisibility by Digit Sum and Product
public:
    bool checkDivisibility(int n) {
    // my-way:  t = (no. of digits)     s = 1
        int sum = 0;
        int prod = 1;
        
        int temp = n;
        while(temp > 0){
            int rem = temp % 10;
            sum += rem;
            prod *= rem;
            temp /=10;
        }

        return (n % (sum + prod) == 0);
    }
};

int main(){
    Solution sol;
    int n = 99; // output: true
    // int n = 23; // output: false
    cout << sol.checkDivisibility(n) << endl;
    return 0;
}