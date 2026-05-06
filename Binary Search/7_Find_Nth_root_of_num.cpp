#include<bits/stdc++.h>	//#include<iostream>
using namespace std;


class Solution {    // **U** means u are given : x^N = M  ==>  find x ?
    public: // ques. available on TUF and GFG (https://www.geeksforgeeks.org/problems/find-nth-root-of-m5843/1)

    long long power(int base, int exp, int M) {
        long long result = 1;

        for(int i = 0; i < exp; i++) {
            result *= base;
            if(result > M) return result; // stop early
        }

        return result;
    }


    int NthRoot(int N, int M) {     // my-way OPTIMAL: t = log(M)   ==> (modified Lower Bound)
        int low = 1, high = M;

        while(low <= high){
            int mid = low + (high-low)/2;

            // long long val = pow(mid, N);     // using predefined func.
                // or..
            long long val = power(mid, N, M);    // using user defined func.
            
            if(val == M) return mid;
            else if(val > M) high = mid - 1;
            else low = mid + 1;
        }

        return -1;
    }
};


int main(){
    Solution obj;
    int N = 3, M = 27;      
    cout << obj.NthRoot(N, M) << endl;
    return 0;
}



// ✅ Prefer user-defined func. over .pow()
// 👉 Reason: The problem is precision, not range

// 🔹 Explanation:
// 🔴 double (used by pow())
// Stores in decimal form
// rounding error

// 🔴 example:  
// pow(3, 3) → 26.999999 (sometimes)
// when type-casted to (long long) → 26    👉 Wrong answer ❌



// 🟢 long long (your manual function)
// Stores exact integers
// No rounding error
// Always precise       eg for above: 27   👉 Always exact ✅
