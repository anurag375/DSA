#include<bits/stdc++.h>	//#include<iostream>
using namespace std;


class Solution {
public:
    int mySqrt_OPTIMAL(int x) {
        // my-way OPTIMAL: (modified Lower Bound) t = log n
        int low = 0, high = x;
        int ans;

        while(low <= high){
            int mid = low + (high-low)/2;

            if((long long)mid * mid <= x){
                ans = mid;
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }

        return ans;
    }


    int mySqrt_BRUTE(int x) {   // t = n
        for(long long i=0; i<=x; i++){
            if(i*i == x) return i;
            else if(i*i > x) return i-1;    // *U* returns 2 if x=8
        }
        return -1;
    }


    int mySqrt_UsingFunction(int x) {   // t = 1
        return int(sqrt(x));
    }
};



int main(){
    int x = 8;
    Solution obj;

    int ans1 = obj.mySqrt_OPTIMAL(x);
    int ans2 = obj.mySqrt_BRUTE(x);
    int ans3 = obj.mySqrt_UsingFunction(x);
    cout << ans1 << endl;
    cout << ans2 << endl;
    cout << ans3 << endl;
    return 0;
}