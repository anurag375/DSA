#include<bits/stdc++.h>	//#include<iostream>
using namespace std;

class Solution {    // 20. Valid Parentheses
public:
    bool isValid(string s) {
    // optimal ONLY (striver-way):   t = n   s = n
        stack<char> st;

        for(char ch:s){
            if(ch == '(' || ch == '{' || ch == '[') st.push(ch);
            else{   // any closing bracket
                if(st.empty()) return false;    // * closing bracket without any opening 
                
                if((st.top() == '(' && ch == ')') || (st.top() == '{' && ch == '}') || (st.top() == '[' && ch == ']'))
                    st.pop();
                else    // * NO match
                    return false;
            }
        }

        return st.empty();  // stack empties when 's' is correct
    }
};

int main(){
    Solution sol;
    // string s = "([])";   // true
    // string s = "([)";   // false
    // string s = "(()";   // false
    string s = "))";   // false ==> Edge case
    cout << sol.isValid(s) << endl;
    
    return 0;
}

