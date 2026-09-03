#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string infixToPostfix(string s) {
    // t = n + n [for outer traversal loop + (for all stack loops throughout the code)]      s = n + n [for stack + ans string]
        int n = s.size();
        int i = 0;
        stack<char> st;
        string ans = "";

        unordered_map<char,int> priority = {{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}, {'^', 3}};  // "(" and ")" will be set 0 by default

        while(i < n){
            if((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9'))    // 1> operands...
                ans += s[i];
            else if(s[i] == '(')    // 2> 
                st.push(s[i]);
            else if(s[i] == ')'){   // 3>
                while(!st.empty() && st.top() != '('){
                    ans += st.top();
                    st.pop();
                }
                st.pop();   // pop out the '(' from stack
            }
            else{   // 4> all operators...
                while(!st.empty() && priority[st.top()] >= priority[s[i]]){      // 4.1> Don't use just ">"
                    ans += st.top();
                    st.pop();
                }
                // else:
                st.push(s[i]);      // 4.2>
            }
            i++;
        }

        // 5> any element left in stack
        while (!st.empty()){
            ans += st.top();
            st.pop();
        }
        
        return ans;
    }
};

int main(){
    Solution sol;
    string s = "a+b*(c^d-e)";     // Output: abcd^e-*+
    // string s = "a+b*c";     // Output: abc*+
    cout << sol.infixToPostfix(s) << endl;
    return 0;
}