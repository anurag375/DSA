#include<bits/stdc++.h>	//#include<iostream>
using namespace std;

class Solution {    // 4006. Count Valid Prefixes
public:
    int countValidPrefixes(string s) {
    // my-way: (contest)   t = n   s = 1
    // *U* alternating string is ONLY possible when BOTH (0,1) have: abs(zeros - ones) <= 1
        int ans = 0;  // total valid counts
        int zeros = 0;
        int ones = 0;

        for(char ch:s){
            if(ch == '0') zeros++;
            else ones++;

            int diff = abs(zeros - ones);
            if(diff == 0 || diff == 1) ans++;
        }

        return ans;
    }
};

int main(){
    Solution sol;
    string s = "00101";     // output: 3
    // string s = "010";     // output: 3
    cout << sol.countValidPrefixes(s) << endl;
    
    return 0;
}