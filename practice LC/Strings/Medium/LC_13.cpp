#include<bits/stdc++.h>	//#include<iostream>
using namespace std;

class Solution {    // 13. Roman to Integer
public:
    int romanToInt(string s) {
    // optimal (most elegant):    TechnosageLearning:     t = n   s = 1
        unordered_map<char, int> mp = {{'I',1}, {'V',5}, {'X', 10}, {'L',50}, {'C',100}, {'D',500}, {'M',1000}};
        
        int n = s.size();
        int ans = mp[ s[n-1] ]; // *U*

        for(int i=n-2; i>=0; i--){
            char curr = s[i];
            char nxt = s[i+1];

            if(mp[curr] < mp[nxt]) ans -= mp[curr];
            else ans += mp[curr];
        }
        return ans;
    }
};

int main(){
    Solution sol;
    string s = "MDCXCV";    // = 1000 + 500 + 100 + 90 + 5
    cout << sol.romanToInt(s) << endl;

    return 0;
}



    // optimal: (very complex) my-way + gpt:     t = n       s = 1
        // unordered_map<char, int> mp = {{'I',1}, {'V',5}, {'X', 10}, {'L',50}, {'C',100}, {'D',500}, {'M',1000}};

        // int n = s.size();
        // if(n == 1) return mp[s[0]];     // *

        // int ans = 0;
        // bool hasCoveredNxt;
        // int i = 0;
        // while(i < n){   // ***U*** don't write n-1 --> handles s="MDCXCV" --> 1695
        //     char curr = s[i];
        //     hasCoveredNxt = false;

        //     if(i == n-1) break; // ***U*** handles s="MDCXCV" --> 1695 (otherwise, last char. would be ignored)

        //     char nxt = s[i + 1];

        //     if(curr == 'I'){
        //         if(nxt == 'V' || nxt == 'X'){    // *U* anything larger than 'I'
        //             ans += mp[nxt] - mp[curr];
        //             i++; // *U* skip the next
        //             hasCoveredNxt = true;
        //         }else ans += mp[curr];
        //     }

        //     else if(curr == 'X'){
        //         if(nxt == 'L' || nxt == 'C'){
        //             ans += mp[nxt] - mp[curr];
        //             i++; 
        //             hasCoveredNxt = true;
        //         }else ans += mp[curr];
        //     }
            
        //     else if(curr == 'C'){
        //         if(nxt == 'D' || nxt == 'M'){
        //             ans += mp[nxt] - mp[curr];
        //             i++; 
        //             hasCoveredNxt = true;
        //         }else ans += mp[curr];
        //     }

        //     else ans += mp[curr];

        //     i++;
        // }

        // if(hasCoveredNxt == false) ans += mp[s[i]];

        // return ans;