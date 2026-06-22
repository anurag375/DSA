#include<bits/stdc++.h>	//#include<iostream>
using namespace std;

class Solution {    // 1189. Maximum Number of Balloons
public:
    int maxNumberOfBalloons(string text) {
    // gpt: (freq. array) (better than mine):     t = (same)       s = (same)
        vector<int> freq(26, 0);

        for(char ch : text) {
            freq[ch - 'a']++;
        }

        return min({
            freq['b' - 'a'],
            freq['a' - 'a'],
            freq['l' - 'a'] / 2,
            freq['o' - 'a'] / 2,
            freq['n' - 'a']
        });
    }
};

int main(){
    Solution sol;
    cout << sol.maxNumberOfBalloons("nlaebolko") << endl;  // 1
    cout << sol.maxNumberOfBalloons("loonbalxballpoon") << endl;  // 2
    return 0;
}


    // my-way ONLY: (unordered map):     t = n       s = 1
        // unordered_map<char,int> mp1 = { {'b',1}, {'a',1}, {'l',2}, {'o',2}, {'n',1} };
        // unordered_map<char,int> mp2;

        // for(char ch:text){
        //     mp2[ch]++;
        // }
        
        // int minRepeat = INT_MAX;    // *U* minimum no. of valid repetitions of "balloon"
        
        // for(const auto &[key, val]:mp1){
        //     // int key = it.first;
        //     if(mp2[key] == 0) return 0;

        //     minRepeat = min(mp2[key] / mp1[key], minRepeat);
        // }
        // return minRepeat;
