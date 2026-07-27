#include<bits/stdc++.h>
using namespace std;

class Solution {    // 242. Valid Anagram
public:
    bool isAnagram(string s, string t) {
    // gpt-way: optimal (almost same as better) (frequency array):
    // t = O(n + k) = O(n)     s = O(26) = O(1)
    // n = size of 's' ; k = total distinct characters
        int freq[26] = {0};  
        // or
        // vector<int> freq(26,0);  // for both s and t
        int n = s.size();
        int m = t.size();
        if(n != m) return false;

        for(int i=0; i<n; i++){
            freq[s[i] - 'a']++;
            freq[t[i] - 'a']--;
        }

        for(int ele:freq)
            if(ele != 0) return false;

        return true;
    }
};

int main(){
    Solution sol;
    string s = "anagram";
    string t = "nagaram";
    
    cout << sol.isAnagram(s, t) << endl;
    return 0;
}




    // gpt-way: better (single map):  t = O(n + k) = O(n)     s = O(26) = O(1)
        // unordered_map<char,int> mp;  // for s

        // int n = s.size();
        // int m = t.size();
        // if(n != m) return false;

        // for(int i=0; i<n; i++){
        //     mp[s[i]]++;
        //     mp[t[i]]--;
        // }

        // for(auto it:mp)
        //     if(it.second != 0) return false;

        // return true;




    // my-way: brute (2 maps):   t = O(n log k + k log k)     s = O(26) = O(1)
    // n = size of s ; k = total distinct characters
        // map<char,int> mp1;  // for s
        // map<char,int> mp2;  // for t

        // int n = s.size();
        // // int m = t.size();
        // // if(n != m) return false;

        // for(int i=0; i<n; i++){
        //     mp1[s[i]]++;
        //     mp2[t[i]]++;
        // }

        // for(auto it:mp1){
        //     char key1 = it.first;
        //     if(mp1[key1] != mp2[key1]) return false;
        // }
        // return true;
        
        //  // or.
        //  // return mp1 == mp2;
