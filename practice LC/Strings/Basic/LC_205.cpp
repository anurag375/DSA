#include<bits/stdc++.h>	//#include<iostream>
using namespace std;

class Solution {    // 205. Isomorphic Strings
public:
    bool isIsomorphic(string s, string t) {
    // codestorywithMIK: (optimal)  t = n       s = k = 1 [max. no. of distinct ascii characters = 256]
        unordered_map<char,char> mp1;   // maps s to t
        unordered_map<char,char> mp2;   // maps t to s
        int n = s.size();

        for(int i=0; i<n; i++){
            if(mp1.find(s[i]) == mp1.end()){ // keys are unique in the map
                mp1[s[i]] = t[i];
            }
            if(mp2.find(t[i]) == mp2.end()) {
                mp2[t[i]] = s[i];
            } 
            
            if(mp1[s[i]] != t[i] || mp2[t[i]] != s[i]) return false;    // ***U***  if previously stored key does not store the value
            
        }
        return true;
    }
};

int main(){
    Solution sol;
    // string s = "paper";
    string s = "waper";
    string t = "title";
    cout << sol.isIsomorphic(s, t) << endl;

    return 0;
}

    // (nice one)
    // brute (my-way RETRY):  t = n*n   s = n   
        // unordered_map<char, char> mp;
        // int n = s.size();
        // int m = t.size();

        // if(n != m) return false;
        // for(int i=0; i<n; i++){
        //     char sCh = s[i];
        //     char tCh = t[i];

        //     // *U* check if 1 vals (in 's') gives 2 val (in 't')
        //     if(mp.find(sCh) != mp.end() && mp[sCh] != tCh) return false;    // **U** 1st string's ch already present, BUT its other value is Diff.

        //     if(mp.find(sCh) != mp.end() && mp[sCh] == tCh) continue;    // **U** prevent adding SAME key-value pairs multiple times, otherwise below for-if part gets activated

        //     for(auto it:mp) // *U* check 1 val (in 't') for 2 vals (in 's')
        //         if(mp[it.first] == tCh) return false;

        //     // All Is Well so far
        //     mp[sCh] = tCh;
        // }
        // return true;




    // [same logic as retry (above)]
    // my-way:  t = n*n       s = n
        // map<int,int> mp;   // maps s to t
        // int n = s.size();

        // for(int i=0; i<n; i++){
        //     if(mp.find(s[i]) == mp.end()){
        //         for(auto it:mp) // *U* ensures that no two characters from s map to the same character in t
        //             if(it.second == t[i]) return false;
                    
        //         mp[s[i]] = t[i];
        //     }else{   // mapping found
        //         if(mp[s[i]] != t[i]) return false; // *U* check if t's character is same as map's value
        //     }
        // }
        // return true;