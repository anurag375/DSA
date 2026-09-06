#include<bits/stdc++.h>
using namespace std;

class Solution {    // 4043. Count Rotations With Exactly K Equal Adjacent Pairs
// my-way: (contest)   t = n*n       s = n    [due to temporary string operations => substr() + char append]
    int findScore(string s){    // (helper func.)
        int score = 0;
        for(int i=0; i<s.size()-1; i++){
            if(s[i] == s[i+1]) score++;
        }
        return score;
    }
    
public:
    int countRotations(string s, int k) {
        int n = s.size();
        int ans = 0;

        if(findScore(s) == k) ans++;  // *U* consider original string 

        int i = 1;
        while(i <= n-1){   // *U* consider for the remaining (n-1) rotations of the string
            char ch = s[0]; 
            s = s.substr(1) + ch;    // send first char to last..
            
            if(findScore(s) == k) ans++;
            i++;
        }
        return ans;
    }
};

int main(){
    Solution sol;
    string s = "aab";   // Output: 2
    int k = 1;
    cout << sol.countRotations(s, k) << endl;    
    return 0;
}