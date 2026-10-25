#include<bits/stdc++.h>	
using namespace std;

class Solution {    // 4092. Binary Digit Score
public:
    int calculateScore(int a, int b) {
        string binA = "";
        string binB = "";
        int s1 = 0;
        int s2 = 0;

        // 1> find binary string:
        while(a > 0){
            int rem = a % 2;
            binA += to_string(rem);
            a = a / 2;
        }
        // reverse(binA.begin(), binA.end()); // *U* no need the get in order
        
        while(b > 0){
            int rem = b % 2;
            binB += to_string(rem);
            b = b / 2;
        }
        // reverse(binB.begin(), binB.end()); 

        // 2> get s1 and s2:
        for(char ch:binA)
            if(ch == '1') s1++;
        
        for(char ch:binB)
            if(ch == '1') s2++;
        // s1 = count(binA.begin(), binA.end(), '1'); 
        // s2 = count(binB.begin(), binB.end(), '1'); 

        return (s1 >= s2) ? (s1 * s2) : (s2 / s1);
    }
};

int main(){
    Solution sol;
    int a = 14, b = 6;  // output: 6
    cout << sol.calculateScore(a, b) << endl;
    return 0;
}