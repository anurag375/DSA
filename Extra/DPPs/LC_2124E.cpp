#include<bits/stdc++.h>
using namespace std;

class Solution {    // 2124. Check if All A's Appears Before All B's
public:
    bool checkString(string s) {
    // my-way:  t=n     s=1
        int n = s.size();

        int i = 0;
        while(i < n && s[i] == 'a') i++; // *U* after this loop, s[i] should always be "b"

        while(i < n){   // check the rest indices
            if(s[i] == 'a') return false;
            i++;
        }

        return true;
    }
};

int main(){
    Solution sol;
    string s = "aaabbb";   // Output: true
    cout << sol.checkString(s) << endl;
    return 0;
}