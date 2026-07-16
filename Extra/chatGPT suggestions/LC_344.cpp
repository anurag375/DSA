#include<bits/stdc++.h>	//#include<iostream>
using namespace std;

class Solution {    // 344. Reverse String
public:
    void reverseString(vector<char>& s) {
    // my-way (good):    t = n/2     s = 1
        int left = 0; 
        int right = s.size() - 1;

        while(left < right){
            swap(s[left], s[right]);
            left++;
            right--;
        }
    }
};

int main(){
    Solution sol;
    vector<char> s = {'h', 'e', 'l', 'l', 'o'};
    sol.reverseString(s);
    for(char c : s){
        cout << c << ' ';
    }
    return 0;
}