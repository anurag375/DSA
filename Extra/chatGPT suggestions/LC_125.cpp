#include<bits/stdc++.h>	//#include<iostream>
using namespace std;

class Solution {    // 125. Valid Palindrome
public:
    bool isPalindrome(string s) {
    // optimal (gpt-way):  t = n   s = 1
        int left = 0;
        int right = s.size() - 1;

        while(left < right){
            while (left < right && !isalnum(s[left])) left++;
            while (left < right && !isalnum(s[right])) right--;

            if (tolower(s[left]) != tolower(s[right]))
                return false;

            left++;
            right--;
        }
        return true;
    }
};

int main(){
    Solution sol;
    string s = "A man, a plan, a canal: Panama";
    cout << sol.isPalindrome(s) << endl;
    return 0;
}


    // my-way BRUTE:  t = O(n + n/2) = O(n)   s = O(n)
        // string newS = "";
        // // 1> keeping valid letters
        // for(int i=0; i<s.size(); i++){
        //     if((s[i] >= 65 && s[i] <= 90) || (s[i] >= 97 && s[i] <= 122) || s[i] >= '0' && s[i] <= '9') newS += tolower(s[i]);   // allows both cases + digits
        // }

        // // 2> palindrome check
        // int left = 0;
        // int right = newS.size() - 1;
        // while(left < right){
        //     if(newS[left] != newS[right]) return false;
        //     left++;
        //     right--;
        // }
        // return true;