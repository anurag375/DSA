#include<bits/stdc++.h>	//#include<iostream>
using namespace std;

class Solution {    // 557. Reverse Words in a String III

// my-way: t = 2n = n [traversal + reversal]   s = 1
    void reverse(string &s, int left, int right){
        while(left < right){
            swap(s[left], s[right]);
            left++;
            right--;
        }
    }
    
public:
    string reverseWords(string s) {
        // string rev = "";
        int left = 0;
        int right = 0;
        int markNextStart = 0;

        while(right < s.size()){
            left = markNextStart;
            right = markNextStart;
            while(right < s.size() && s[right] != ' '){
                right++;
            }
            reverse(s, left, right-1);  // *U* 'right' takes 1 step back

            if(right + 1 >= s.size()) break;    // can igmore this and simply write the outer loop as => while (markNextStart < s.size())
            markNextStart = right+1;
        }
        return s;
    }
};

int main(){
    Solution sol;
    string s = "Let's take LeetCode contest";
    cout << sol.reverseWords(s) << endl;
    
    return 0;
}