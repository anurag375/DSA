#include<bits/stdc++.h>	//#include<iostream>
using namespace std;

class Solution {
public:
string reverseWords(string s) {
    // gpt brute:    t = n*n
        string ans = "";
        string word = "";

        for (char ch : s) {
            if (ch != ' ') {
                word += ch;
            } else {
                if (!word.empty()) {
                    if (ans.empty())
                        ans = word;
                    else
                        ans = word + " " + ans;

                    word = "";
                }
            }
        }

        // Handle the last word
        if (!word.empty()) {
            if (ans.empty())
                ans = word;
            else
                ans = word + " " + ans;
        }

        return ans;
    }
};

int main(){
    
    return 0;
}


    // gpt brute:    t = n*n
        // string ans = "";
        // string word = "";

        // for (char ch : s) {
        //     if (ch != ' ') {
        //         word += ch;
        //     } else {
        //         if (!word.empty()) {
        //             if (ans.empty())
        //                 ans = word;
        //             else
        //                 ans = word + " " + ans;

        //             word = "";
        //         }
        //     }
        // }

        // // Handle the last word
        // if (!word.empty()) {
        //     if (ans.empty())
        //         ans = word;
        //     else
        //         ans = word + " " + ans;
        // }

        // return ans;