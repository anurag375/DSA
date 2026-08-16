#include<bits/stdc++.h>
#include <numeric>  // *U* added this separately [since VS code intellisense issue with gcd() function]
using namespace std;

class Solution {    // 4010. Maximize Pair Strength Using GCD
public:
    int find_gcd(int a, int b){     // the 'gcd' method has some issues to run // ** MUST also explore the Euclidean algo.
        int gcd = 1;
        for(int i=1; i<=min(a,b); i++){
            if(a % i == 0 && b % i == 0)
                gcd = i;
        }
        return gcd;
    }

    long long maxPairStrength(vector<int>& nums) {
    // my-way: (contest)   
    // t = n*n * log(n)  [for loop + gcd] [log(n) is ONLY when u use the build-in method (gcd()); otherwise 'n' in my case]     s = 1
        int n = nums.size();
        long long maxStrength = 0;

        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                int gcdValue = find_gcd(nums[i], nums[j]);  
                long long strength = (long long) nums[i] * nums[j];
                strength /= pow(gcdValue, 2);
                maxStrength = max(strength, maxStrength);
            }
        }
        return maxStrength;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {2,3,5};     // output: 15
    // vector<int> nums = {3,3};     // output: 1
    cout << sol.maxPairStrength(nums) << endl;
    
    return 0;
}