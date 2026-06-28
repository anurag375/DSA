#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int upperBound(vector<int> &nums, int x){
        int n = nums.size();
        int low = 0, high = n - 1;
        int ans = n; // default if no element > x
        
        while(low <= high){
            int mid = low + (high - low) / 2;
            
            if(nums[mid] > x){
                ans = mid;      // possible answer, still move to find a better one
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};

int main(){
    vector<int> nums = {1, 3, 5, 7, 9};
    int x = 5;

    Solution obj;
    int idx = obj.upperBound(nums, x);

    if(idx < nums.size())
        cout << "Upper bound index: " << idx << ", value: " << nums[idx] << endl;
    else
        cout << "Upper bound index: " << idx << " (no element > " << x << ")" << endl;

    return 0;
}