#include<bits/stdc++.h>	//#include<iostream>
using namespace std;

class Solution {    // 387. First Unique Character in a String
public:
    int firstUniqChar(string s) {
    // (my way + gpt):  t = 2n    s = 1
        unordered_map<char,int> mp;  // unordered_map does not preserve the order of characters.
            // or..
        // map<char,int> mp;   // map<char, int> ONLY iterates in alphabetical order (a-z)

        // 1> store
        for(char ch:s) mp[ch]++;

        // 2> find the first unique char.
        for(char ch:s){     // **U** DO NOT iterate through the map
            if(mp[ch] == 1) return s.find(ch);
        }

        return -1;
    }
};

int main(){
    Solution sol;
    string s = "loveleetcode";
    cout << "index no: " << sol.firstUniqChar(s) << endl;
    
    return 0;
}