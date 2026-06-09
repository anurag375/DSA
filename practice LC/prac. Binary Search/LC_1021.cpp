#include<bits/stdc++.h>	//#include<iostream>
using namespace std;

class Solution {    // 1021. Remove Outermost Parentheses

public:
    string removeOuterParentheses(string s) {
    // GPT-way: optimal (easier): t = n      s = n
        int cnt = 0;
        string ans = "";

        for(char ch:s){
            if(ch == '('){
                if(cnt > 0) ans += ch;  // else: skip it
                cnt++;
            }

            else{   // ch == ')'
                cnt--;
                if(cnt > 0) ans += ch;  // else: skip it
            }
        }

        return ans;
    }
};

int main(){
    Solution sol;
    // string s = "(()())(())";
    string s = "(()())(())(()(()))";
    cout << sol.removeOuterParentheses(s) << endl;
    
    return 0;
}


    // my-way ONLY: optimal (lengthy): t = n      s = n
        // int n = s.size();
        // int startIdx = -1, endIdx = -1;
        // int cnt = 0;
        // string ans = "";

        // for(int i=0; i<n; i++){
        //     if(cnt == 0 && s[i] == '('){
        //         startIdx = i;
        //     }

        //     if(s[i] == '(') cnt++;
        //     else cnt--;

        //     if(cnt == 0 && s[i] == ')'){
        //         endIdx = i;
        //         ans += s.substr(startIdx + 1, endIdx - (startIdx + 1)); // ***U***
        //     }

        // }

        // return ans;