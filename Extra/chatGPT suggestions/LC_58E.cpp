#include<bits/stdc++.h>	//#include<iostream>
using namespace std;

class Solution {    // 58. Length of Last Word

public:
    int lengthOfLastWord(string s) {
    // optimal (my-way):    t = n   s = 1
        int cnt = 0;
        int i = s.size() - 1;

        // 1> Skip trailing spaces
        while(i >= 0 && s[i] == ' ') i--;

        // 2> Count characters of the last word (until the next space or string 's' is finished)
        while(i >= 0 && s[i] != ' '){
            cnt++;
            i--;
        }

        return cnt;
    }
};

int main(){
    Solution sol;
    string s = "Let's take LeetCode contest";
    cout << sol.lengthOfLastWord(s) << endl;
    
    return 0;
}