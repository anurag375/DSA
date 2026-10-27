#include<bits/stdc++.h>
using namespace std;

class Solution {    // 3963. Create Grid With Exactly One Path
public:
    vector<string> createGrid(int m, int n) {
    // retry: (optimal)
        vector<string> ans(m, "");  // initialization is imp..
        for(int j=0; j<n; j++) ans[0] += '.';  // first row full of "."

        for(int i=1; i<m; i++){
            for(int j=0; j<n-1; j++) ans[i] += '#';
            ans[i] += '.';  // last column full of "."  ==> rest are "#"
        }

        return ans;
    }
};

int main(){
    Solution sol;
    int m = 2, n = 3;  // output: ["...","##."]
    vector<string> ans = sol.createGrid(m, n);
    for(string s:ans) cout << s << endl;
    
    return 0;
}