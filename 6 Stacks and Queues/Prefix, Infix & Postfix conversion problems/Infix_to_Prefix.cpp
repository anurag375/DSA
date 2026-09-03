#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string infixToPrefix(string& str) {
    // t = n/2+ 2n + n/2 [for reversal+ (traversal + all stack loops throughout the code) + inner loops]      s = n + n [for stack + ans string]
        string s = str;
        int n = s.size();
        stack<char> st;
        string ans = "";
        
        unordered_map<char,int> priority = {{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}, {'^', 3}};  // "(" and ")" will be set 0 by default
        
        // s = reverseString(s);
        reverse(s.begin(), s.end());

        for(char& ch:s){
            if(ch == '(') ch = ')';
            else if(ch == ')') ch = '(';    // Can not be "if" here
        }

        int i = 0;
        while(i < n){
            if((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9'))    // 1> operands...
                ans += s[i];
            else if(s[i] == '(')
                st.push(s[i]);
            else if(s[i] == ')'){
                while(!st.empty() && st.top() != '('){
                    ans += st.top();
                    st.pop();
                }
                st.pop();
            }
            else{   // operators...
                if(s[i] == '^'){
                    while(!st.empty() && priority[st.top()] >= priority[s[i]]){  // NO ^ can be together
                        ans += st.top();
                        st.pop();
                    }
                }else{
                    while(!st.empty() && priority[st.top()] > priority[s[i]]){  // Don't use >=
                        ans += st.top();
                        st.pop();
                    }
                }
                // else:
                st.push(s[i]);
            }
            i++;
        }

        // any leftovers
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end()); // don't worry "ans" doesn't have any parenthesis
        return ans;
    }
};

int main(){
    Solution sol;
    string s = "(a+b)*c-d+f";     // Output: +-*+abcdf
    // string s = "(a+b)*c";     // Output: *+abc
    cout << sol.infixToPrefix(s) << endl;
    return 0;
}