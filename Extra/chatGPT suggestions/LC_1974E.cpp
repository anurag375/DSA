#include<bits/stdc++.h>
using namespace std;

class Solution {    // 1974. Minimum Time to Type Word Using Special Typewriter
public:
    int minTimeToType(string word) {
    // optimal: (my-way + gpt):    t = n   s = 1
        int n = word.size();
        int ans = n;    // *U* 1> time taken for typing each letter

        // 2> calculating the traversal
        int diff = abs(word[0] - 'a');  // **U** 'abs' handles -ve => eg: a-c = -2
        ans += min(diff, 26 - diff);
        
        for(int i=1; i<n; i++){
            diff = abs(word[i] - word[i-1]);
            ans += min(diff, 26 - diff);
        }

        return ans;
    }
};

// Flash notes:
// - Circular distance: min(diff, 26 - diff)
// - Always make diff non-negative using abs().
// - Initial pointer is 'a', so handle the first character separately.
// - ans = n counts typing time; add only movement time in the loop.

int main(){
    Solution sol;
    string word = "bza";    // output: 7
    cout << sol.minTimeToType(word) << endl;
    return 0;
}