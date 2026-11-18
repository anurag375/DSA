#include<bits/stdc++.h>	//#include<iostream>
using namespace std;

class Solution {
public:
    string digitSum(string s, int k) {
    // my-way: ***U***

        // 1> repeat till length is shortened:
        while(s.size() > k){    // breaks when: size <= k
            int n = s.size();
            string newS = "";
            int startIdx = 0;    // (variable index)

            while(startIdx < n){  // 2> cover entire "s" one-by-one:
                int endIdx = min(startIdx + k - 1, n-1);    // *U* prevents exceeding "s" size

                // 3> sum of digits:
                int sum = 0;
                for(int i= startIdx; i<=endIdx; i++){
                    sum += s[i] - '0'; // simple "int()" will give ascii values
                }

                newS = newS + to_string(sum);
                startIdx = endIdx + 1;   // *
            }

            s = newS;
        }
        return s;
    }
};

int main(){
    Solution sol;
    cout << sol.digitSum("11111222223", 3) << endl;     // Output: "135"
    return 0;
}