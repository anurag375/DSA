#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string PrefixToPostfix(string s) {
    // t = n + 1 + (n1 + n2)    [for traversal + stack top/pop operations + for adding 2 strings (lang. specific)]        s = n
        int n = s.size();
        stack<string> st;
        
        unordered_map<char,int> priority = {{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}, {'^', 3}};  // "(" and ")" will be set 0 by default
        
        int i = n-1;
        while(i >= 0){
            if((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9'))    // 1> operands
                st.push(string(1, s[i]));   // ⭐ char to string conversion..
            else{   // 2> only operators [NO parenthesis]
                string t1 = st.top();
                st.pop();
                string t2 = st.top();
                st.pop();

                string newS = t1 + t2 + s[i];
                st.push(newS);
            }
            i--;
        }

        return st.top();
    }
};

int main(){
    Solution sol;
    string s = "/-ab*+def";     // Output: ab-de+f*/
    cout << sol.PrefixToPostfix(s) << endl;
    return 0;
}