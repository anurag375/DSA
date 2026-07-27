#include<bits/stdc++.h>	//#include<iostream>
using namespace std;

class Solution {    // 151. Reverse words in a given string / Palindrome Check
public:
    string reverseWords(string s) {
    // ⭐ better (my-way): (Vector + Reverse)  ==> BEST to understand + clean code
    // t = 4n = n       s = 2n = n
        int n = s.size();
        vector<string> v;

        int i = 0;
        int j = 0;

        // 1> skip leading spaces
        while(j < n && s[j] == ' ') j++;

        while(j < n){
            // 2> traverse the complete word, then store it in vector
            i = j;
            while(j < n && s[j] != ' ') j++;
            v.push_back(s.substr(i, j-i));

            // 3> find next word's start index
            while(j < n && s[j] == ' ') j++;
        }

        // 4> reverse vector
        reverse(v.begin(), v.end());

        // 5>
        string ans = "";
        for(int i=0; i<v.size(); i++){
            // ans += ' ';
            if(i != 0) ans += ' ';
            ans += v[i];  // ** don't use  ans = ans + " " + st; 
        }
        // return ans.substr(1, ans.size() - 1);   // since the start has a unwanted space, remove it..
        return ans;
    }
};


int main(){
    Solution sol;
    // string s = "  hello  world!  ";
    // string s = "blue";
    string s = "  the sky   is blue  ";

    string ans = sol.reverseWords(s);
    cout << ans << " : " << ans.size() << endl;
    return 0;
}


    // optimal: @codestorywithMIK : (GOOD but complex): t = n
        // int n = s.size();

        // reverse(s.begin(), s.end());

        // int low = 0, high = 0;
        // int i = 0;
        // while(i < n){
        //     while(i < n && s[i] != ' '){
        //         swap(s[high++], s[i++]);    // my-way
        //         // or
        //         // s[high++] = s[i++];
        //     }
            
        //     // again reverse
        //     if(low < high){
        //         reverse(s.begin() + low, s.begin() + high);
        //         s[high] = ' ';  // adds space after every word
        //         high++;
        //         low = high;
        //     }

        //     i++;
        // }

        // s = s.substr(0, high-1); // removes the last space added after the last word
        // return s; 



// ============ (below sol.s are NOT worth) ============

    // my-way brute: (maybe hard) t = n*n (because of front/reverse string concatenation) 
        // int n = s.size();

        // reverse(s.begin(), s.end());

        // int low = 0, high = 0;
        // int i = 0;
        // while(i < n){
        //     while(i < n && s[i] != ' '){
        //         swap(s[high++], s[i++]);    // my-way
        //         // or
        //         // s[high++] = s[i++];
        //     }
            
        //     // again reverse
        //     if(low < high){
        //         reverse(s.begin() + low, s.begin() + high);
        //         s[high] = ' ';  // adds space after every word
        //         high++;
        //         low = high;
        //     }

        //     i++;
        // }

        // s = s.substr(0, high-1); // removes the last space added after the last word
        // return s; 


        

// my-way brute: (lengthy) t = n*n (because of front/reverse string concatenation) 
//     string removeEdgeSpaces(string s){
//         int n = s.size();
//         int start = 0, end = n - 1;

//         while(s[start] == ' '){
//             start++;
//         }
//         while(s[end] == ' '){
//             end--;
//         }

//         return s.substr(start, end-start+1); // *U*
//     }

// public:
//     string reverseWords(string s) {
//         string temp = removeEdgeSpaces(s);
//         int n = temp.size();
//         string ans = "";

//         string word = "";
//         for(int i=0; i<n; i++){
//             char ch = temp[i];

//             if(i == n-1){
//                 word += ch;
//                 ans = word + " " + ans;
//                 word = "";
//             }
//             else if((ch == ' ')){
//                 if(temp[i+1] == ' ') continue;  // *U* skips multiple spaces in between
//                 else{
//                     ans = word + " " + ans;
//                     word = "";
//                 }
//             }else word += ch;
//         }

//         ans = removeEdgeSpaces(ans); 
//         return ans;
//     }





    // gpt brute:(don't know)    t = n*n
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