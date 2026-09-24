#include<bits/stdc++.h>
using namespace std;

class Solution {    // 3550. Smallest Index With Digit Sum Equal to Index
// my-way:  t = (total no. of digits in all indices)    s = 1
    int sumOfDigits(int num){
        int sum = 0;
        while(num > 0){
            sum += (num % 10);
            num /= 10; 
        }
        return sum;
    }

public:
    int smallestIndex(vector<int>& nums) {
        int n = nums.size();

        for(int i=0; i<n; i++){
            if(sumOfDigits(nums[i]) == i) return i;
        }
        return -1;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {1,3,2};
    cout << sol.smallestIndex(nums) << endl;    // output: 2
    return 0;
}