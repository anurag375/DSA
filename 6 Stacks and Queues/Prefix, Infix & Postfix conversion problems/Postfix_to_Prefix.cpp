#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string PostfixToPrefix(string s) {
    // t = n + 1 + (n1 + n2)    [for traversal + stack top/pop operations + for adding 2 strings (lang. specific)]        s = n
        int n = s.size();
        stack<string> st;
        
        unordered_map<char,int> priority = {{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}, {'^', 3}};  // "(" and ")" will be set 0 by default
        
        int i = 0;
        while(i < n){
            if((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9'))    // 1> operands...
                st.push(string(1, s[i]));   // ⭐ char to string conversion..
            else{   // 2> only operators... [NO parenthesis]
                string sFirst = st.top();
                st.pop();
                string sSecond = st.top();
                st.pop();

                string newS = s[i] + sSecond + sFirst;
                st.push(newS);
            }
            i++;
        }

        return st.top();
    }
};

int main(){
    Solution sol;
    string s = "ab-de+f*/";     // Output: /-ab*+def
    cout << sol.PostfixToPrefix(s) << endl;
    return 0;
}